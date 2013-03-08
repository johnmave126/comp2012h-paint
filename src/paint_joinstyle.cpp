/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_joinstyle.cpp
 *
 * Boundary join style config, configuring boundary join style
 */

#include "paint_joinstyle.h"
#include <qapplication.h>
#include <qstring.h>
#include <qwidget.h>
#include <qdialog.h>
#include <qsignalmapper.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>

PaintJoinstyle::PaintJoinstyle(QWidget* parent, int width)
:QWidget(parent), container(3, Qt::Horizontal, "Boundary Join Style", this) {
	setFixedSize(width, 50);
	
	//Set margin
	container.setFixedSize(width - 20, 50);
	container.move(10, 0);
	
	//Set exclusive
	container.setExclusive(true);
	
	QRadioButton *miter, *bevel, *round;
	//Used to map signals to one slot
	QSignalMapper *signalMapper = new QSignalMapper(this);
	
	miter = new QRadioButton("Miter Join", &container);
	//Default
	miter->setChecked(true);
	signalMapper->setMapping(miter, 0);
	QObject::connect(miter, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	bevel = new QRadioButton("Bevel Join", &container);
	signalMapper->setMapping(bevel, 1);
	QObject::connect(bevel, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	round = new QRadioButton("Round Join", &container);
	signalMapper->setMapping(round, 2);
	QObject::connect(round, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	QObject::connect(signalMapper, SIGNAL(mapped(int)),
		this, SLOT(selectorValueChanged(int)));
}

PaintJoinstyle::~PaintJoinstyle() {
}

void PaintJoinstyle::selectorValueChanged(int v) {
	switch(v) {
		case 0:
			emit valueChanged(Qt::MiterJoin);
			break;
		case 1:
			emit valueChanged(Qt::BevelJoin);
			break;
		case 2:
			emit valueChanged(Qt::RoundJoin);
			break;
	}
}
