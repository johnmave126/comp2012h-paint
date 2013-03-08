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
#include "paint_drawtype.h"
#include "paint_slider.h"
#include <qapplication.h>
#include <qmainwindow.h>
#include <qpixmap.h>
#include <qpainter.h>
#include <qdialog.h>

PaintRect::PaintRect(QMainWindow *parent)
:PaintTool(parent), fill_mode(FG), type(Rectangle) {
	//Default settings
	drawPen.setCapStyle(Qt::SquareCap);
	
	//Lay the config window
	config_window.resize(500, 330);
	config_window.setFixedSize(500, 330);
	config_window.setCaption("Rectangle Dialog");
	
	//Add drawtype
	PaintDrawtype *drawtype = new PaintDrawtype(&config_window,
		config_window.width());
	
	//Add slider
	PaintSlider *slider = new PaintSlider(&config_window,
		config_window.width(), "Boundary Width");
	slider->setMin(1);
	slider->setMax(40);
	slider->move(0, 300);
	
	//Connect Attributes
	QObject::connect(drawtype, SIGNAL(valueChanged(PaintDrawType)),
		this, SLOT(setDrawType(PaintDrawType)));
	QObject::connect(slider, SIGNAL(valueChanged(int)),
		this, SLOT(setPenWidth(int)));
}

PaintRect::~PaintRect() {
}

QPixmap PaintRect::begin(QPixmap dst, QColor fcolor, QColor bcolor, QPoint newPoint) {
	//Set canvas and color
	my_target = dst;
	drawPen.setColor(fcolor);
	if(fill_mode == FG) {
		fillBrush.setColor(fcolor);
	}
	else {
		fillBrush.setColor(bcolor);
	}
	
	//Start painter
	tmp_target = my_target;
	tmpBufferPainter.begin(&tmp_target);
	tmpBufferPainter.setPen(drawPen);
	tmpBufferPainter.setBrush(fillBrush);
	
	//Store point
	start_point = newPoint;
	
	//Draw the point
	return process(newPoint);
}

QPixmap PaintRect::process(QPoint newPoint) {
	int w1 = newPoint.x() - start_point.x(),
		w2 = newPoint.y() - start_point.y();
	
	//Temporarily reset painter
	tmpBufferPainter.end();
	
	//Reset to original
	tmp_target = my_target;
	
	//Start again
	tmpBufferPainter.begin(&tmp_target);
	tmpBufferPainter.setPen(drawPen);
	tmpBufferPainter.setBrush(fillBrush);
	
	//Draw the graph
	switch(type) {
		case Rectangle:
			tmpBufferPainter.drawRect(start_point.x(), start_point.y(),
				w1, w2);
			break;
		case RRectangle:
			tmpBufferPainter.drawRoundRect(start_point.x(), start_point.y(),
				w1, w2);
			break;
		case Circle:
			if(w1 > w2)
				w1 = w2;
			else
				w2 = w1;
		case Ellipse:
			tmpBufferPainter.drawEllipse(start_point.x(), start_point.y(),
				w1, w2);
			break;
	}
	
	//Return tmp pixmap
	return tmp_target;
}

QPixmap PaintRect::end() {
	//Reset painter
	tmpBufferPainter.end();
	
	//Copy back to original
	my_target = tmp_target;
	
	//Return final pixmap
	return my_target;
}

void PaintRect::config() {
	config_window.exec();
}

void PaintRect::setPenWidth(int r) {
	drawPen.setWidth(r);
}

void PaintRect::setDrawType(PaintDrawType r) {
	type = r;
}
