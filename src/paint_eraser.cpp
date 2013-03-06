/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_eraser.cpp
 *
 * Eraser, a basic tool. Can erase part of the canvas.
 */

#include "paint_eraser.h"
#include <qapplication.h>
#include <qmainwindow.h>
#include <qpixmap.h>
#include <qpainter.h>

PaintEraser::PaintEraser(QMainWindow *parent)
:PaintTool(parent) {
	drawPen.setWidth(10);
	drawPen.setCapStyle(Qt::SquareCap);
}

PaintEraser::~PaintEraser() {
}

QPixmap PaintEraser::begin(QPixmap dst, QColor fcolor, QColor bcolor, QPoint newPoint) {
	//Set canvas and color
	my_target = dst;
	drawPen.setColor(bcolor);
	
	//Reset painter
	bufferPainter.begin(&my_target);
	bufferPainter.setPen(drawPen);
	
	//Draw the point
	return addPoint(newPoint);
}

QPixmap PaintEraser::addPoint(QPoint newPoint) {
	//Draw the point
	bufferPainter.drawPoint(newPoint);
	
	//Return tmp pixmap
	return my_target;
}

QPixmap PaintEraser::end() {
	//Reset painter
	bufferPainter.end();
	
	//Return final pixmap
	return my_target;
}

void PaintEraser::config() {
	QFrame *config_window = new QDialog(my_parent);
	config_window->resize(300,100);
}
