/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_widget.cpp
 *
 * Mainwindow of the program
 */

#include "paint_widget.h"
#include <qmainwindow.h>
#include <qapplication.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qkeysequence.h>

MyMainWindow::MyMainWindow(QWidget* parent, const char* name)
:QMainWindow(parent, name)
{
	int tmp_id; //Store id allocated by qt
	
	//Create File Menu
	//File Menu Begin
	QPopupMenu* file = new QPopupMenu(this);
	
	//Create Image Section
	file->insertItem("New image", this, SLOT(OnNewImage()), QKeySequence::New);
	file->insertItem("Load image", this, SLOT(OnLoadImage()), QKeySequence::Open);
	file->insertItem("Save image", this, SLOT(OnSaveImage()), QKeySequence::Save);
	file->insertSeparator();
	
	//Create Color Section
	file->insertItem("Foreground color", this, SLOT(ChangeFGColor()));
	file->insertItem("Background color", this, SLOT(ChangeBGColor()));
	file->insertSeparator();
	
	//Create Exit Section
	file->insertItem("Exit", this, SLOT(OnExit()), CTRL+KEY_X);	
	
	//Insert File Menu
	menuBar()->insertItem("File", file);
	//File Menu End
	
	//Create Edit Menu
	//Edit Menu Begin
	QPopupMenu* edit = new QPopupMenu(this);
	
	//Create Edit items
	edit->insertItem("Undo", this, SLOT(OnUndo()), QKeySequence::Undo);
	edit->insertItem("Redo", this, SLOT(OnRedo()), QKeySequence::Redo);
	edit->insertItem("Clear All", this, SLOT(OnClearAll()));
	edit->insertItem("Resize", this, SLOT(OnResizeImage()), CTRL+Key_R);
	
	//Insert Edit Menu
	menuBar()->insertItem("Edit", edit);
	//Edit Menu End
	
	//Create View Menu
	//View Menu Begin
	QPopupMenu* view = new QPopupMenu(this);
	
	//Create View items
	tmp_id = edit->insertItem("Tool Bar", this, SLOT(ToggleToolBar()));
	edit->setItemChecked(tmp_id, true);
	
	//Insert View Menu
	menuBar()->insertItem("View", edit);
	//View Menu End
	
	//Create Help Menu
	//Help Menu Begin
	QPopupMenu* help = new QPopupMenu(this);
	
	//Create Help items
	help->insertItem("About", this, SLOT(ShowAbout()));
	
	//Insert View Menu
	menuBar()->insertItem("View", edit);
	//View Menu End
}

MyMainWindow::~MyMainWindow()
{
	delete image;
}

void MyMainWindow::paintEvent(QPaintEvent* e)
{
	QPainter paint(this);
	if (! image->isNull())
	{
		paint.drawPixmap(0, menuBar()->height(), (*image));
	}
}

void MyMainWindow::OnLoadImage()
{
	QString s = QFileDialog::getOpenFileName("", "*.bmp", this, "", "Load image...");
	if (! s.isNull())
	{
		image->load(s);
		this->update();
	}
}

void MyMainWindow::mousePressEvent(QMouseEvent * e)
{
	if(image->	isNull()) {
		OnLoadImage();
	}
	else {
		if(e->x() <= image->width() && e->y() > menuBar()->height() && e->y() <= menuBar()->height() + image->height()) {
			QMessageBox::about( this, "bitmap", "Mouse click event!");
		}
	}
}