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
#include <qdialog.h>
#include <qlistbox.h>

PaintPen::PaintPen(QMainWindow *parent)
:PaintTool(parent) {
	drawPen.setWidth(1);
	drawPen.setCapStyle(Qt::FlatCap);
}

PaintPen::~PaintPen() {
}

QPixmap PaintPen::begin(QPixmap dst, QColor fcolor, QColor bcolor, QPoint newPoint) {
	//Set canvas and color
	my_target = dst;
	drawPen.setColor(fcolor);
	
	//Start painter
	bufferPainter.begin(&my_target);
	bufferPainter.setPen(drawPen);
	
	//Store point
	last_point = newPoint;
	
	//Draw the point
	return process(newPoint);
}

QPixmap PaintPen::process(QPoint newPoint) {
	//Draw the point
	bufferPainter.drawLine(last_point, newPoint);
	last_point = newPoint;
	
	//Return tmp pixmap
	return my_target;
}

QPixmap PaintPen::end() {
	//Reset painter
	bufferPainter.end();
	
	//Return final pixmap
	return my_target;
}

void PaintPen::config() {
	QDialog *config_window = new QDialog(my_parent);
	config_window->resize(300,100);
	QListBox *test = new QListBox(config_window);
	config_window->exec();
	
}
