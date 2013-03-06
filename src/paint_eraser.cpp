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
#include <qdialog.h>

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
	
	//Reset real painter
	bufferPainter.begin(&my_target);
	bufferPainter.setPen(drawPen);

	//Draw the point
	return process(newPoint);
}

QPixmap PaintEraser::process(QPoint newPoint) {
	//Erase a region
	bufferPainter.drawPoint(newPoint);
	
	//Assign tmporary target
	bufferPainter.end();
	tmp_target = my_target;
	bufferPainter.begin(&my_target);
	bufferPainter.setPen(drawPen);
	
	//Reset tmp painter
	tmpBufferPainter.begin(&tmp_target);
	tmpBufferPainter.setPen(tmpPen);
	
	//Draw the border
	int w = drawPen.width();
	tmpBufferPainter.drawRect(newPoint.x() - (w >> 1),
		newPoint.y() - (w >> 1), w, w);
	
	tmpBufferPainter.end();
	
	//Return tmp pixmap
	return tmp_target;
}

QPixmap PaintEraser::end() {
	//Reset painter
	bufferPainter.end();
	
	//Return final pixmap
	return my_target;
}

void PaintEraser::config() {
	QDialog *config_window = new QDialog(my_parent);
	config_window->resize(300,100);
}
