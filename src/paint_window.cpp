/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_window.cpp
 *
 * Mainwindow of the program
 */

#include "paint_window.h"
#include "paint_canvas.h"
#include "paint_toolbar.h"
#include <qmainwindow.h>
#include <qapplication.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qaction.h>
#include <qpixmap.h>
#include <qkeysequence.h>
#include <qscrollview.h>

PaintMainWindow::PaintMainWindow(QWidget* parent, const char* name)
:QMainWindow(parent, name), canvas(new PaintCanvas()),
 viewport(new QScrollView(this)), 
 tools(new PaintToolBar(this, "tool bar", canvas)) {
	//Create menubar and toolbar
	CreateMenuBar();
	setDockMenuEnabled(false);
	
	//Set as the central widget to resize automatically
	setCentralWidget(viewport);
	
	//Append canvas to scroll view
	viewport->addChild(canvas);
	
	//Resize window to a resonable size
	setBaseSize(100, 100);
	resize(800, 600);
}

PaintMainWindow::~PaintMainWindow() {
}

void PaintMainWindow::CreateMenuBar() {
	
	//Create File Menu
	//File Menu Begin
	QPopupMenu* file = new QPopupMenu(this);
	
	//Create Image Section
	file->insertItem("&New image", this, SLOT(OnNewImage()), CTRL+Key_N);
	file->insertItem("&Load image", this, SLOT(OnLoadImage()), CTRL+Key_O);
	file->insertItem("&Save image", this, SLOT(OnSaveImage()), CTRL+Key_S);
	file->insertSeparator();
	
	//Create Color Section
	file->insertItem("&Foreground color", this, SLOT(ChangeFGColor()));
	file->insertItem("&Background color", this, SLOT(ChangeBGColor()));
	file->insertSeparator();
	
	//Create Exit Section
	file->insertItem("&Exit", this, SLOT(OnExit()), CTRL+Key_X);	
	
	//Insert File Menu
	menuBar()->insertItem("&File", file);
	//File Menu End
	
	//Create Edit Menu
	//Edit Menu Begin
	QPopupMenu* edit = new QPopupMenu(this);
	
	//Create Edit items
	edit->insertItem("&Undo", canvas, SLOT(undo()), CTRL+Key_Z);
	edit->insertItem("&Redo", canvas, SLOT(redo()), CTRL+Key_Y);
	edit->insertItem("&Clear All", canvas, SLOT(clearAll()));
	edit->insertItem("Re&size", this, SLOT(OnResizeImage()), CTRL+Key_R);
	
	//Insert Edit Menu
	menuBar()->insertItem("&Edit", edit);
	//Edit Menu End
	
	//Create View Menu
	//View Menu Begin
	QPopupMenu* view = new QPopupMenu(this);
	
	//Create ToolBar toggler
	QAction *ToolBar_t = new QAction("&Tool Bar", 0, this);
	QObject::connect(ToolBar_t, SIGNAL(activated()),
		this, SLOT(ToggleToolBar()));
	//Set ToolBar toggler to be checkable
	ToolBar_t->setToggleAction(true);
	ToolBar_t->setOn(true);
	ToolBar_t->addTo(view);
	//Connect ToolBar state to ToolBar toggler
	QObject::connect(tools, SIGNAL(visibilityChanged(bool)), 
		ToolBar_t, SLOT(toggle()));
	
	
	//Insert View Menu
	menuBar()->insertItem("&View", view);
	//View Menu End
	
	//Create Help Menu
	//Help Menu Begin
	QPopupMenu* help = new QPopupMenu(this);
	
	//Create Help items
	help->insertItem("&About", this, SLOT(ShowAbout()));
	
	//Insert Help Menu
	menuBar()->insertItem("&Help", help);
	//Help Menu End
}

void PaintMainWindow::mousePressEvent(QMouseEvent *e) {
	//Handle left click inside window
	if(e->button() == Qt::LeftButton) {
		//No image is loaded
		if(!canvas->isLoaded())
			OnNewImage();
	}
	//Handle right click inside window
	else if(e->button() == Qt::RightButton) {
		//Ask canvas for configuration
		canvas->config();
	}
}
