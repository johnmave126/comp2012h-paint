/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_linemode.cpp
 *
 * Line mode config, configuring line mode
 */

#include "paint_linemode.h"
#include <qapplication.h>
#include <qstring.h>
#include <qwidget.h>
#include <qdialog.h>
#include <qsignalmapper.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>

PaintLinemode::PaintLinemode(QWidget* parent, int width)
:QWidget(parent), container(3, Qt::Vertical, "Line Mode", this) {
	setFixedSize(width, 60);
	
	//Set margin
	container.setFixedSize(width - 20, 100);
	
	//Set exclusive
	container.setExclusive(true);
	
	QRadioButton *sing, *poly;
	//Used to map signals to one slot
	QSignalMapper *signalMapper = new QSignalMapper(this);
	
	sing = new QRadioButton("Single", &container);
	//Default
	flat->setChecked(true);
	signalMapper->setMapping(sing, 0);
	QObject::connect(sing, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	poly = new QRadioButton("Poly", &container);
	signalMapper->setMapping(poly, 1);
	QObject::connect(poly, SIGNAL(clicked()),
		signalMapper, SLOT(map()));

	QObject::connect(signalMapper, SIGNAL(mapped(int)),
		this, SLOT(selectorValueChanged(int)));
}

PaintLinemode::~PaintLinemode() {
}

void PaintLinemode::selectorValueChanged(int v) {
	switch(v) {
		case 0:
			emit valueChanged(Sing);
			break;
		case 1:
			emit valueChanged(Poly);
			break;
	}
}
