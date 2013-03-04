/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_pen.cpp
 *
 * Pen, a basic tool to be draw
 */

#include "paint_pen.h"
#include <qapplication.h>
#include <qmainwindow.h>
#include <qpixmap.h>
#include <qpainter.h>

PaintPen::PaintPen(QMainWindow *parent) {
}

~PaintPen::~PaintPen() {
}

QPixmap PaintPen::begin(QPixmap dst, QColor color, QPoint newPoint) {
	//Set canvas and color
	my_target = dst;
	drawPen.setColor(color);
	
	//Reset painter
	bufferPainter.begin(my_target);
	bufferPainter.setPen(drawPen);
	
	//Draw the point
	return addPoint(newPoint);
}

QPixmap PaintPen::addPoint(QPoint newPoint) {
	//Draw the point
	bufferPainter.drawPoint(newPoint);
	
	//Return tmp pixmap
	return my_target;
}

QPixmap PaintPen::end() {
	//Reset painter
	bufferPainter.end();
	
	//Return final pixmap
	return my_target
}

void PaintPen::config() {
}