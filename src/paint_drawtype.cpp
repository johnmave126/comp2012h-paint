/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_drawtype.cpp
 *
 * Draw type config, configuring draw type
 */

#include "paint_drawtype.h"
#include <qapplication.h>
#include <qstring.h>
#include <qwidget.h>
#include <qdialog.h>
#include <qsignalmapper.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>

PaintDrawtype::PaintDrawtype(QWidget* parent, int width)
:QWidget(parent), container(4, Qt::Horizontal, "Draw Type", this) {
	setFixedSize(width, 50);
	
	//Set margin
	container.setFixedSize(width - 20, 50);
	container.move(10, 0);
	
	//Set exclusive
	container.setExclusive(true);
	
	QRadioButton *rect, *rrect, *circ, *elli;
	//Used to map signals to one slot
	QSignalMapper *signalMapper = new QSignalMapper(this);
	
	rect = new QRadioButton("Rectangle", &container);
	//Default
	rect->setChecked(true);
	signalMapper->setMapping(rect, 0);
	QObject::connect(rect, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	rrect = new QRadioButton("Round Rectangle", &container);
	signalMapper->setMapping(rrect, 1);
	QObject::connect(rrect, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	circ = new QRadioButton("Circle", &container);
	signalMapper->setMapping(circ, 2);
	QObject::connect(circ, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	elli = new QRadioButton("Ellipse", &container);
	signalMapper->setMapping(elli, 3);
	QObject::connect(elli, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	QObject::connect(signalMapper, SIGNAL(mapped(int)),
		this, SLOT(selectorValueChanged(int)));
}

PaintDrawtype::~PaintDrawtype() {
}

void PaintDrawtype::selectorValueChanged(int v) {
	switch(v) {
		case 0:
			emit valueChanged(Rectangle);
			break;
		case 1:
			emit valueChanged(RRectangle);
			break;
		case 2:
			emit valueChanged(Circle);
			break;
		case 3:
			emit valueChanged(Ellipse);
			break;
	}
}
