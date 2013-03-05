/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_canvas.cpp
 *
 * Canvas, area to be drawn upon
 * Receive all the signal, and process them.
 */

#include "paint_canvas.h"
#include "paint_toolbar.h"
#include "paint_pen.h"

#include <qmainwindow.h>
#include <qapplication.h>
#include <qpixmap.h>
#include <qcolor.h>
#include <qpainter.h>
#include <qstring.h>
#include <qstringlist.h>
#include <qregexp.h>
#include <iostream>
#include <list>
using namespace std;

PaintCanvas::PaintCanvas()
:fgColor(0, 0, 0), bgColor(255, 255, 255), ToolState(Pen) {
	//Assign the current pointer for history use
	Current = ImageHistory.begin();
	
	//Reset canvas size to zero
	setFixedSize(0, 0);
}

PaintCanvas::~PaintCanvas() {
}

void PaintCanvas::changeImage(const int w, const int h) {
	//Clear History
	ImageHistory.clear();
	
	//Set canvas size
	setFixedSize(w, h);
	
	//Insert into history
	ImageHistory.insert(ImageHistory.end(), QPixmap(w, h));
	Current = ImageHistory.begin();
	(*Current).fill(bgColor);
	buffer = *Current;
	
	//Repaint
	repaint();
}

void PaintCanvas::changeImage(const QString fileName) {
	QPixmap newImage(fileName);
	
	//Check the validity of the file
	if(!newImage.isNull()) {
		//Set canvas size
		setFixedSize(newImage.width(), newImage.height());
		
		//Clear History
		ImageHistory.clear();
		
		//Insert into history
		ImageHistory.insert(ImageHistory.end(), newImage);
		Current = ImageHistory.begin();
		buffer = *Current;
	}
}

void PaintCanvas::resizeImage(const int w, const int h) {
	QPixmap new_image;
	QPainter painter;
	int ori_w, ori_h;
	
	//Set canvas size
	setFixedSize(w, h);
	//Set pixmap size
	new_image = (*Current);
	ori_w = new_image.width();
	ori_h = new_image.height();
	//First resize horizontally
	new_image.resize(w, ori_h);
	painter.begin(&new_image);
	//Fill extra area if necessary
	if(w > ori_w) {
		painter.fillRect(ori_w, 0, w - ori_w, ori_h, bgColor);
	}
	painter.end();
	//Then resize vertically
	new_image.resize(w, h);
	painter.begin(&new_image);
	//Fill extra area if necessary
	if(h > ori_h) {
		painter.fillRect(0, ori_h, w, h - ori_h, bgColor);
	}
	painter.end();
	
	//Clear history
	ImageHistory.clear();
	ImageHistory.insert(ImageHistory.end(), new_image);
	Current = ImageHistory.begin();
	buffer = *Current;
	
	//Call for repaint
	repaint();
}

void PaintCanvas::saveImage(QString fileName, const QString filter) {
	//Extract the format from filter
	int len_format = filter.find(' ');
	QString format = filter.left(len_format);
	format = format.upper();
	
	//Append to fileName if suffix is absent
	QString suffix;
	int possible_start = filter.find('(') + 1,
		possible_end = filter.find(')') - 1;
	ASSERT(possible_start <= possible_end);
	//Clip the section of filters
	QString format_filters = filter.mid(possible_start,
		possible_end - possible_start + 1);
	QStringList filters = QStringList::split(' ', format_filters);
	QStringList::iterator f_it;
	//Iterate in possible filters to find match
	for(f_it = filters.begin(); f_it != filters.end(); f_it++) {
		QRegExp reg(*f_it, false, true);
		if(suffix.isEmpty()) {
			suffix = (*f_it).right((*f_it).length() - 2);
		}
		if(reg.exactMatch(fileName))
			break;
	}
	
	//Suffix is missing, add it
	if(f_it == filters.end() && !suffix.isEmpty()) {
		fileName = fileName + '.' + suffix;
	}
	
	//Save it
	(*Current).save(fileName, format);
}

void PaintCanvas::clearAll() {
	//Check image
	if(ImageHistory.empty()) {
		return;
	}
	
	//Always create a copy before operation
	QPixmap copy = *Current;
	
	//Clear with bgColor
	copy.fill(bgColor);
	
	//Forward the history using copy
	forward(copy);
}

void PaintCanvas::config() {
}

bool PaintCanvas::isLoaded() {
	//Not loaded only if the history is blank
	return !ImageHistory.empty();
}

void PaintCanvas::paintEvent(QPaintEvent *e) {
	if(ImageHistory.empty()) {
		//If no image is loaded, erase the region
		erase(0, 0, width(), height());
	}
	else {
		//If there is imaged loaded, draw it
		bitBlt(this, 0, 0,
			&buffer, 0, 0, buffer.width(), buffer.height());
	}
}

void PaintCanvas::mousePressEvent(QMouseEvent *e) {
	if(e->button() == Qt::LeftButton) {
		buffer = penTool.begin(*Current, fgColor, e->pos());
	}
	else {
		e->ignore();
	}
}

void PaintCanvas::mouseMoveEvent(QMouseEvent *e) {
	if(e->state() == Qt::LeftButton) {
		if(!penTool.isBegin()) {
			buffer = penTool.begin(*Current, fgColor, e->pos());
		}
		else {
			buffer = penTool.addPoint(e->pos());
			repaint();
		}
	}
	else {
		e->ignore();
	}
}

void PaintCanvas::mouseReleaseEvent(QMouseEvent *e) {
	if(e->button() == Qt::LeftButton) {
		forward(penTool.end());
	}
	else {
		e->ignore();
	}
}
