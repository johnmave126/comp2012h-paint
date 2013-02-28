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
#include <qmainwindow.h>
#include <qapplication.h>
#include <qpixmap.h>
#include <qcolor.h>
#include <qpainter.h>
#include <iostream>
#include <list>
using namespace std;

PaintCanvas::PaintCanvas()
:fgColor(0, 0, 0), bgColor(255, 255, 255) {
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
	ImageHistory.insert(ImageHistory.begin(), QPixmap(w, h));
	Current = ImageHistory.begin();
	(*Current).fill(bgColor);
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
		ImageHistory.insert(ImageHistory.begin(), newImage);
		Current = ImageHistory.begin();
	}
}

void PaintCanvas::saveImage(const QString fileName, const QString filter) {
	//Find the format from filter
	int len_format = filter.find(' ') + 1;
	QString format = filter.left(len_format);
	format = format.upper();
	
	//Append to fileName if format is absent
	QStringList possible_formats = QStringList::split(QRegExp("\\*\\.\\w+"), filter);
	cout << possible_formats.join(",") << endl;
	
	//(*Current).save(fileName, format);
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
			&(*Current), 0, 0, (*Current).width(), (*Current).height());
	}
}
