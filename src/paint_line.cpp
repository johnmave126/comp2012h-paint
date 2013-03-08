/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_line.cpp
 *
 * Line, a basic tool, draw lines or polylines
 */

#include "paint_line.h"
#include "paint_linestyle.h"
#include "paint_capstyle.h"
#include "paint_slider.h"
#include <qapplication.h>
#include <qmainwindow.h>
#include <qpixmap.h>
#include <qpainter.h>
#include <qdialog.h>

PaintLine::PaintLine(QMainWindow *parent)
:PaintTool(parent), mode(Sing) {
	//Default Pen
	drawPen.setWidth(1);
	drawPen.setCapStyle(Qt::FlatCap);
	
	//Lay the config window
	config_window.resize(300, 200);
	config_window.setFixedSize(300, 200);
	config_window.setCaption("Line Dialog");
	
	//Add linestyle
	PaintLinestyle *linestyle = new PaintLinestyle(&config_window, 200);
	
	//Add Capstyle
	PaintCapstyle *capstyle = new PaintCapstyle(&config_window,
		100, Qt::Vertical);
	capstyle->move(200, 0);
	
	//Add slider
	PaintSlider *slider = new PaintSlider(&config_window,
		config_window.width(), "Line Width");
	slider->setMin(1);
	slider->setMax(40);
	slider->move(0, 180);
	
	//Connect Attributes
	QObject::connect(linestyle, SIGNAL(valueChanged(Qt::PenStyle)),
		this, SLOT(setPenStyle(Qt::PenStyle)));
	QObject::connect(capstyle, SIGNAL(valueChanged(Qt::PenCapStyle)),
		this, SLOT(setPenCap(Qt::PenCapStyle)));
	QObject::connect(slider, SIGNAL(valueChanged(int)),
		this, SLOT(setLineWidth(int)));
}

PaintLine::~PaintLine() {
}

QPixmap PaintLine::begin(QPixmap dst, QColor fcolor, QColor bcolor, QPoint newPoint) {
	//Set canvas and color
	my_target = dst;
	drawPen.setColor(fcolor);
	
	if(mode == Sing) {
		last_point = newPoint;
	}
	else {
		if(tmp_target.isNull()) {
			//Null tmp_target indicates end of polyline
			//Start new one
			last_point = newPoint;
		}
	}
	
	//Start painter
	tmp_target = my_target;
	tmpBufferPainter.begin(&tmp_target);
	tmpBufferPainter.setPen(drawPen);
	
	//Draw the line
	return process(newPoint);
}

QPixmap PaintLine::process(QPoint newPoint) {
	//Temporarily reset painter
	tmpBufferPainter.end();
	
	//Reset to original
	tmp_target = my_target;
	
	//Start again
	tmpBufferPainter.begin(&tmp_target);
	tmpBufferPainter.setPen(drawPen);
	
	//Draw the line
	tmpBufferPainter.drawLine(last_point, newPoint);
	tmp_point = newPoint;
	
	//Return tmp pixmap
	return tmp_target;
}

QPixmap PaintLine::end() {
	if(tmpBufferPainter.isActive()) {
		//Reset painter
		tmpBufferPainter.end();
	}
	else {
		//Only occur when special case in poly
		return QPixmap();
	}
	
	//Copy to original
	my_target = tmp_target;
	if(mode == Sing) {
		//Null tmp_target indicates end of polyline
		//Prevent poly mess
		tmp_target.resize(0, 0);
	}
	else {
		last_point = tmp_point;
	}
	
	//Return final pixmap
	return my_target;
}

void PaintLine::dblEnd() {
	if(mode == Poly) {
		//Null tmp_target indicates end of polyline
		tmp_target.resize(0, 0);
	}
}

void PaintLine::config() {
	config_window.exec();
}

bool PaintLine::isBegin() {
	return !tmp_target.isNull();
}

void PaintLine::setPenCap(Qt::PenCapStyle r) {
	drawPen.setCapStyle(r);
}

void PaintLine::setPenStyle(Qt::PenStyle r) {
	drawPen.setStyle(r);
}

void PaintLine::setLineWidth(int r) {
	drawPen.setWidth(r);
}
