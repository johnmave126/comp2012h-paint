/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_rect.cpp
 *
 * Rect, a basic tool, draw or fill a rectangle and variation
 */

#include "paint_rect.h"
#include <qapplication.h>
#include <qmainwindow.h>
#include <qpixmap.h>
#include <qpainter.h>
#include <qdialog.h>

PaintRect::PaintRect(QMainWindow *parent)
:PaintTool(parent), fill_mode(FG) {
	drawPen.setCapStyle(Qt::SquareCap);
}

PaintRect::~PaintRect() {
}

QPixmap PaintRect::begin(QPixmap dst, QColor fcolor, QColor bcolor, QPoint newPoint) {
	//Set canvas and color
	my_target = dst;
	tmp_target = my_target;
	drawPen.setColor(fcolor);
	if(fill_mode == FG) {
		fillBrush.setColor(fcolor);
	}
	else {
		fillBrush.setColor(bcolor);
	}
	
	//Start painter
	bufferPainter.begin(&tmp_target);
	bufferPainter.setPen(drawPen);
	bufferPainter.setBrush(fillBrush);
	
	//Store point
	start_point = newPoint;
	
	//Draw the point
	return process(newPoint);
}

QPixmap PaintRect::process(QPoint newPoint) {
	//Temporarily reset painter
	bufferPainter.end();
	
	//Reset to original
	tmp_target = my_target;
	
	//Start again
	bufferPainter.begin(&tmp_target);
	bufferPainter.setPen(drawPen);
	bufferPainter.setBrush(fillBrush);
	
	//Draw the point
	bufferPainter.drawRect(start_point.x(), start_point.y(),
		newPoint.x(), newPoint.y());
	
	//Return tmp pixmap
	return tmp_target;
}

QPixmap PaintRect::end() {
	//Reset painter
	bufferPainter.end();
	
	//Copy back to original
	my_target = tmp_target;
	
	//Return final pixmap
	return my_target;
}

void PaintRect::config() {
	QDialog *config_window = new QDialog(my_parent);
	config_window->resize(300,100);
}
