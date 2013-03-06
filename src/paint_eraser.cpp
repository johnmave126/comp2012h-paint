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
	tmpPen.setWidth(1);
	tmpPen.setCapStyle(Qt::SquareCap);
}

PaintEraser::~PaintEraser() {
}

QPixmap PaintEraser::begin(QPixmap dst, QColor fcolor, QColor bcolor, QPoint newPoint) {
	//Set canvas and color
	my_target = dst;
	drawPen.setColor(bcolor);
	int r = 255 - bcolor.red(),
		g = 255 - bcolor.green(),
		b = 255 - bcolor.blue();
	tmpPen.setColor(QColor(r, g, b));
	
	//Draw the point
	return addPoint(newPoint);
}

QPixmap PaintEraser::process(QPoint newPoint) {
	//Reset painter
	bufferPainter.begin(&my_target);
	bufferPainter.setPen(drawPen);
	
	//Draw the point
	bufferPainter.drawPoint(newPoint);
	
	//Reset painter
	bufferPainter.end();
	
	//Draw the border
	tmp_target = my_target;
	bufferPainter.begin(&tmp_target);
	bufferPainter.setPen(tmpPen);
	
	int w = drawPen.width();
	bufferPainter.drawRect(newPoint.x() - (w >> 1),
		newPoint.y() - (w >> 1), w, w);
	
	bufferPainter.end();
	
	//Return tmp pixmap
	return tmp_target;
}

QPixmap PaintEraser::end() {
	
	//Return final pixmap
	return my_target;
}

void PaintEraser::config() {
	QFrame *config_window = new QDialog(my_parent);
	config_window->resize(300,100);
}
