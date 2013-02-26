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
#include <qmainwindow.h>
#include <qapplication.h>
#include <qpixmap.h>
#include <qtoolbar.h>
#include <qtoolbutton.h>

PaintCanvas::PaintToolBar(QMainWindow *parent = 0, const char *name = 0)
:PaintToolBar(parent, name){
	
	QPixmap newIcon, openIcon, saveIcon, undoIcon, redoIcon,
		clearIcon, resizeIcon, penIcon, lineIcon, eraserIcon,
		rectIcon, fgIcon, bgIcon;
	QToolButton *newTool, *openTool, *saveTool, *undoTool, 
		*redoTool, *clearTool, *resizeTool, *penTool, *lineTool,
		*eraserTool, *rectTool, *fgTool, *bgTool;
	
	//Set Title
	this->setLabel("Tool Bar");
	
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
	
	//Insert Buttons
	newTool = new QToolButton(newIcon, "New Image", "Create a new image", 
		parent, SLOT(parent->OnNewImage()), this, "new image");
	openTool = new QToolButton(openIcon, "Open Image", "Open an existing image", 
		parent, SLOT(parent->OnLoadImage()), this, "open image");
	saveTool = new QToolButton(saveIcon, "Save Image", "Save current image", 
		parent, SLOT(parent->OnNewImage()), this, "save image");
	this->addSeperator();
	undoTool = new QToolButton(undoIcon, "Undo", "Undo last operation", 
		parent, SLOT(parent->OnUndo()), this, "undo");
	redoTool = new QToolButton(redoIcon, "Redo", "Redo the operation reverted", 
		parent, SLOT(parent->OnRedo()), this, "redo");
	clearTool = new QToolButton(clearIcon, "Clear All", "Clear the canvas to background color", 
		parent, SLOT(parent->OnClearAll()), this, "clear all");
	resizeTool = new QToolButton(resizeIcon, "Resize", "Resize the canvas", 
		parent, SLOT(parent->OnResizeImage()), this, "resize");
	this->addSeperator();
	penTool = new QToolButton(penIcon, "Pen", "Draw with pen tool", 
		parent, SLOT(parent->OnNewImage()), this, "pen");
	lineTool = new QToolButton(lineIcon, "Line", "Draw with line tool", 
		parent, SLOT(parent->OnNewImage()), this, "line");
	eraserTool = new QToolButton(eraserIcon, "Eraser", "Erase certain area of canvas using an eraser", 
		parent, SLOT(parent->OnNewImage()), this, "eraser");
	rectTool = new QToolButton(rectIcon, "Rectangle", "Draw a rectangle", 
		parent, SLOT(parent->OnNewImage()), this, "rectangle");
	this->addSeperator();
	fgTool = new QToolButton(fgIcon, "Color", "Set foreground color", 
		parent, SLOT(parent->OnNewImage()), this, "fgcolor");
	bgTool = new QToolButton(bgIcon, "BG Color", "Set background color", 
		parent, SLOT(parent->OnNewImage()), this, "bgcolor");
}

PaintCanvas::~PaintToolBar() {
}