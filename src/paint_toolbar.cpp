/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_toolbar.cpp
 *
 * Toolbar of the window
 */

#include "paint_toolbar.h"
#include "paint_window.h"
#include <qmainwindow.h>
#include <qapplication.h>
#include <qpixmap.h>
#include <qtoolbar.h>
#include <qtoolbutton.h>
#include <qdir.h>

PaintToolBar::PaintToolBar(QMainWindow *parent, const char *name)
:QToolBar(parent, name) {
	QPixmap newIcon, openIcon, saveIcon, undoIcon, redoIcon,
		clearIcon, resizeIcon, penIcon, lineIcon, eraserIcon,
		rectIcon, fgIcon, bgIcon;
	QToolButton *newTool, *openTool, *saveTool, *undoTool, 
		*redoTool, *clearTool, *resizeTool, *penTool, *lineTool,
		*eraserTool, *rectTool, *fgTool, *bgTool;
	QString tmpDir;
	
	//Set Title
	this->setLabel("Tool Bar");
	
	//Set working directory to application directory
	tmpDir = QDir::currentDirPath();
	QDir::setCurrent(qApp->applicationDirPath());
	
	//Import Icons
	newIcon = QPixmap("icon/new_icon.bmp");
	openIcon = QPixmap("icon/open_icon.bmp");
	saveIcon = QPixmap("icon/save_icon.bmp");
	undoIcon = QPixmap("icon/undo_icon.bmp");
	redoIcon = QPixmap("icon/redo_icon.bmp");
	clearIcon = QPixmap("icon/clearall_icon.bmp");
	resizeIcon = QPixmap("icon/resize_icon.bmp");
	penIcon = QPixmap("icon/pen_icon.bmp");
	lineIcon = QPixmap("icon/line_icon.bmp");
	eraserIcon = QPixmap("icon/eraser_icon.bmp");
	rectIcon = QPixmap("icon/rect_icon.bmp");
	fgIcon = QPixmap("icon/fcolor_icon.bmp");
	bgIcon = QPixmap("icon/bcolor_icon.bmp");
	
	//Reset working directory
	QDir::setCurrent(tmpDir);
	
	//Insert Buttons
	newTool = new QToolButton(newIcon, "New Image", "Create a new image", 
		parent, SLOT(OnNewImage()), this, "new image");
	openTool = new QToolButton(openIcon, "Open Image", "Open an existing image", 
		parent, SLOT(OnLoadImage()), this, "open image");
	saveTool = new QToolButton(saveIcon, "Save Image", "Save current image", 
		parent, SLOT(OnSaveImage()), this, "save image");
	this->addSeparator();
	undoTool = new QToolButton(undoIcon, "Undo", "Undo last operation", 
		parent, SLOT(OnUndo()), this, "undo");
	redoTool = new QToolButton(redoIcon, "Redo", "Redo the operation reverted", 
		parent, SLOT(OnRedo()), this, "redo");
	clearTool = new QToolButton(clearIcon, "Clear All", "Clear the canvas to background color", 
		parent, SLOT(OnClearAll()), this, "clear all");
	resizeTool = new QToolButton(resizeIcon, "Resize", "Resize the canvas", 
		parent, SLOT(OnResizeImage()), this, "resize");
	this->addSeparator();
	penTool = new QToolButton(penIcon, "Pen", "Draw with pen tool", 
		parent, NULL, this, "pen");
	lineTool = new QToolButton(lineIcon, "Line", "Draw with line tool", 
		parent, NULL, this, "line");
	eraserTool = new QToolButton(eraserIcon, "Eraser", "Erase certain area of canvas using an eraser", 
		parent, NULL, this, "eraser");
	rectTool = new QToolButton(rectIcon, "Rectangle", "Draw a rectangle", 
		parent, NULL, this, "rectangle");
	this->addSeparator();
	fgTool = new QToolButton(fgIcon, "Color", "Set foreground color", 
		parent, SLOT(ChangeFGColor()), this, "fgcolor");
	bgTool = new QToolButton(bgIcon, "BG Color", "Set background color", 
		parent, SLOT(ChangeBGColor()), this, "bgcolor");
}

PaintToolBar::~PaintToolBar() {
}
