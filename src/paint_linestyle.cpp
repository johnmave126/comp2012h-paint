/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_linestyle.cpp
 *
 * Linestyle config, configuring linestyle
 */

#include "paint_linestyle.h"
#include <qapplication.h>
#include <qstring.h>
#include <qwidget.h>
#include <qdialog.h>
#include <qsignalmapper.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>

PaintLinestyle::PaintLinestyle(QWidget* parent, int width)
:QWidget(parent), container(5, Qt::Vertical, "Line Style", this) {
	//Set widget size
	setFixedSize(width, 180);
	
	//Set margin
	container.setFixedSize(width - 20, 180);
	container.move(10, 0);
	
	//Set exclusive
	container.setExclusive(true);
	
	QRadioButton *solid, *dash, *dot, *dashdot, *dashdotdot;
	//Used to map signals to one slot
	QSignalMapper *signalMapper = new QSignalMapper(this);
	
	solid = new QRadioButton("Solid line", &container);
	//Default
	solid->setChecked(true);
	signalMapper->setMapping(solid, 0);
	QObject::connect(solid, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	dash = new QRadioButton("Dash line", &container);
	signalMapper->setMapping(dash, 1);
	QObject::connect(dash, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	dot = new QRadioButton("Dot line", &container);
	signalMapper->setMapping(dot, 2);
	QObject::connect(dot, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	dashdot = new QRadioButton("Dash dot line", &container);
	signalMapper->setMapping(dashdot, 3);
	QObject::connect(dashdot, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	dashdotdot = new QRadioButton("Dash dot dot line", &container);
	signalMapper->setMapping(dashdotdot, 4);
	QObject::connect(dashdotdot, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	QObject::connect(signalMapper, SIGNAL(mapped(int)),
		this, SLOT(selectorValueChanged(int)));
}

PaintLinestyle::~PaintLinestyle() {
}

void PaintLinestyle::selectorValueChanged(int v) {
	switch(v) {
		case 0:
			emit valueChanged(Qt::SolidLine);
			break;
		case 1:
			emit valueChanged(Qt::DashLine);
			break;
		case 2:
			emit valueChanged(Qt::DotLine);
			break;
		case 3:
			emit valueChanged(Qt::DashDotLine);
			break;
		case 4:
			emit valueChanged(Qt::DashDotDotLine);
			break;
	}
}
