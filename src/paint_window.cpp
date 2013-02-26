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
#include <qpixmap.h>
#include <qkeysequence.h>
#include <qscrollview.h>

PaintMainWindow::PaintMainWindow(QWidget* parent, const char* name)
:QMainWindow(parent, name) {
	
	//Create menubar and toolbar
	CreateMenuBar();
	tools = new PaintToolBar(this, "tool bar");
	QObject::connect(tools, SIGNAL(visibilityChanged(visible)), 
		this, SLOT(JustifyToggle(visible)));
	
	//Create scrollview container
	viewport = new QScrollView(this);
	//Set as the central widget to resize automatically
	setCentralWidget(viewport);	
	
	//Create canvas
	canvas = new PaintCanvas();
	
	//Append canvas to scroll view
	viewport->addChild(canvas);
}

PaintMainWindow::~PaintMainWindow() {
	delete canvas;
	delete viewport;
	delete tools;
}

void PaintMainWindow::CreateMenuBar() {
	int tmp_id; //Store id allocated by qt
	
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
	edit->insertItem("&Undo", this, SLOT(OnUndo()), CTRL+Key_Z);
	edit->insertItem("&Redo", this, SLOT(OnRedo()), CTRL+Key_Y);
	edit->insertItem("&Clear All", this, SLOT(OnClearAll()));
	edit->insertItem("Re&size", this, SLOT(OnResizeImage()), CTRL+Key_R);
	
	//Insert Edit Menu
	menuBar()->insertItem("&Edit", edit);
	//Edit Menu End
	
	//Create View Menu
	//View Menu Begin
	QPopupMenu* view = new QPopupMenu(this);
	
	//Create View items
	tmp_id = view->insertItem("&Tool Bar", this, SLOT(ToggleToolBar()));
	view->setItemChecked(tmp_id, true);
	
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

void PaintMainWindow::JustifyToggle(bool visible) {
	//Find view menu
	QPopupMenu* view = findItem(idAt(2));
	//Set toolbar check state
	view->setItemChecked(view->idAt(0), visible);
}