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
#include <qapplication.h>
#include <qmainwindow.h>
#include <qpixmap.h>
#include <qpainter.h>
#include <qdialog.h>

PaintLine::PaintLine(QMainWindow *parent)
:PaintTool(parent), mode(Poly) {
	drawPen.setWidth(1);
	drawPen.setCapStyle(Qt::FlatCap);
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
