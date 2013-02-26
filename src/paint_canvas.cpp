/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_canvas.cpp
 *
 * Canvas, area to be drawn upon
 * Receive all the signal, and process them.
 */

#include "paint_canvas.h"
#include "paint_toolbar.h"
#include <qmainwindow.h>
#include <qapplication.h>
#include <qpixmap.h>
#include <qpainter.h>

PaintCanvas::PaintCanvas() {
	PaintToolBar *t = new PaintToolBar(this, "test");
}

PaintCanvas::~PaintCanvas() {
}
