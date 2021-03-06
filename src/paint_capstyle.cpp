/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_capstyle.cpp
 *
 * Capstyle config, configuring capstyle
 */

#include "paint_capstyle.h"
#include <qapplication.h>
#include <qstring.h>
#include <qwidget.h>
#include <qdialog.h>
#include <qsignalmapper.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>

PaintCapstyle::PaintCapstyle(QWidget* parent, int width, Qt::Orientation orientation)
:QWidget(parent), container(3, orientation, "Cap Style", this) {
	if(orientation == Qt::Horizontal) {
		setFixedSize(width, 50);
	}
	else {
		setFixedSize(width, 100);
	}
	
	//Set margin
	if(orientation == Qt::Horizontal) {
		container.setFixedSize(width - 20, 50);
	}
	else {
		container.setFixedSize(width - 20, 100);
	}
	container.move(10, 0);
	
	//Set exclusive
	container.setExclusive(true);
	
	QRadioButton *flat, *square, *round;
	//Used to map signals to one slot
	QSignalMapper *signalMapper = new QSignalMapper(this);
	
	flat = new QRadioButton("Flat", &container);
	//Default
	flat->setChecked(true);
	signalMapper->setMapping(flat, 0);
	QObject::connect(flat, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	square = new QRadioButton("Square", &container);
	signalMapper->setMapping(square, 1);
	QObject::connect(square, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	round = new QRadioButton("Round", &container);
	signalMapper->setMapping(round, 2);
	QObject::connect(round, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	QObject::connect(signalMapper, SIGNAL(mapped(int)),
		this, SLOT(selectorValueChanged(int)));
}

PaintCapstyle::~PaintCapstyle() {
}

void PaintCapstyle::selectorValueChanged(int v) {
	switch(v) {
		case 0:
			emit valueChanged(Qt::FlatCap);
			break;
		case 1:
			emit valueChanged(Qt::SquareCap);
			break;
		case 2:
			emit valueChanged(Qt::RoundCap);
			break;
	}
}
