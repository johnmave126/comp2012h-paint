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

#include <iostream>
using namespace std;

PaintToolBar::PaintToolBar(QMainWindow *parent, const char *name)
:QToolBar("Tool Bar", parent, parent->menuBar(), false, name){
	QPixmap newIcon, openIcon, saveIcon, undoIcon, redoIcon,
		clearIcon, resizeIcon, penIcon, lineIcon, eraserIcon,
		rectIcon, fgIcon, bgIcon;
	QToolButton *newTool, *openTool, *saveTool, *undoTool, 
		*redoTool, *clearTool, *resizeTool, *penTool, *lineTool,
		*eraserTool, *rectTool, *fgTool, *bgTool;
	
	//Set Title
	//this->setLabel("Tool Bar");
	
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
		parent, NULL, this, "new image");
	openTool = new QToolButton(openIcon, "Open Image", "Open an existing image", 
		parent, NULL, this, "open image");
	saveTool = new QToolButton(saveIcon, "Save Image", "Save current image", 
		parent, NULL, this, "save image");
	this->addSeparator();
	undoTool = new QToolButton(undoIcon, "Undo", "Undo last operation", 
		parent, NULL, this, "undo");
	redoTool = new QToolButton(redoIcon, "Redo", "Redo the operation reverted", 
		parent, NULL, this, "redo");
	clearTool = new QToolButton(clearIcon, "Clear All", "Clear the canvas to background color", 
		parent, NULL, this, "clear all");
	resizeTool = new QToolButton(resizeIcon, "Resize", "Resize the canvas", 
		parent, NULL, this, "resize");
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
		parent, NULL, this, "fgcolor");
	bgTool = new QToolButton(bgIcon, "BG Color", "Set background color", 
		parent, NULL, this, "bgcolor");
}

PaintToolBar::~PaintToolBar() {
}
