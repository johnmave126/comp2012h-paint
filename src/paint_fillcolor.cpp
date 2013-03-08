/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_fillcolor.cpp
 *
 * Fill color config, configuring fill color
 */

#include "paint_fillcolor.h"
#include <qapplication.h>
#include <qstring.h>
#include <qwidget.h>
#include <qdialog.h>
#include <qsignalmapper.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>

PaintFillcolor::PaintFillcolor(QWidget* parent, int width)
:QWidget(parent), container(2, Qt::Vertical, "Fill Color", this) {
	setFixedSize(width, 130);
	
	//Set margin
	container.setFixedSize(width - 20, 130);
	container.move(10, 0);
	
	//Set exclusive
	container.setExclusive(true);
	
	QRadioButton *fg, *bg;
	//Used to map signals to one slot
	QSignalMapper *signalMapper = new QSignalMapper(this);
	
	fg = new QRadioButton("Foreground", &container);
	//Default
	fg->setChecked(true);
	signalMapper->setMapping(fg, 0);
	QObject::connect(fg, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	bg = new QRadioButton("Background", &container);
	signalMapper->setMapping(bg, 1);
	QObject::connect(bg, SIGNAL(clicked()),
		signalMapper, SLOT(map()));

	QObject::connect(signalMapper, SIGNAL(mapped(int)),
		this, SLOT(selectorValueChanged(int)));
}

PaintFillcolor::~PaintFillcolor() {
}

void PaintFillcolor::selectorValueChanged(int v) {
	switch(v) {
		case 0:
			emit valueChanged(FG);
			break;
		case 1:
			emit valueChanged(BG);
			break;
	}
}
