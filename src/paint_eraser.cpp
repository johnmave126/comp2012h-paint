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
#include <iostream>
using namespace std;

PaintEraser::PaintEraser(QMainWindow *parent)
:PaintTool(parent) {
	width = 10;
	drawPen.setWidth(1);
	drawPen.setCapStyle(Qt::SquareCap);
}

PaintEraser::~PaintEraser() {
}

QPixmap PaintEraser::begin(QPixmap dst, QColor fcolor, QColor bcolor, QPoint newPoint) {
	//Set canvas and color
	my_target = dst;
	int r = 255 - bcolor.red(),
		g = 255 - bcolor.green(),
		b = 255 - bcolor.blue();
	drawPen.setColor(QColor(r, g, b));
	
	//Start real painter
	bufferPainter.begin(&my_target);
	bufferPainter.setBackgroundColor(bcolor);

	//Draw the point
	return process(newPoint);
}

QPixmap PaintEraser::process(QPoint newPoint) {
	//Erase a region
	bufferPainter.eraseRect(newPoint.x() - (width >> 1),
		newPoint.y() - (width >> 1), width, width);

	//Reset tmp painter
	tmp_target = my_target;
	tmpBufferPainter.begin(&tmp_target);
	tmpBufferPainter.setPen(drawPen);
	
	//Draw the border
	tmpBufferPainter.drawRect(newPoint.x() - (width >> 1),
		newPoint.y() - (width >> 1), width, width);
	
	//Reset tmp painter
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
