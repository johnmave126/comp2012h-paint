/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_tool.cpp
 *
 * PaintTool, the base class of all the tool
 */

#include "paint_tool.h"
#include <qapplication.h>
#include <qmainwindow.h>
#include <qpixmap.h>
#include <qpen.h>

PaintPen::PaintPen(QMainWindow *parent)
:drawPen(QColor(0, 0, 0)), my_parent(parent) {
}

~PaintPen::~PaintPen() {
	my_parent = NULL;
}