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
#include <qradiobutton.h>

PaintCapstyle::PaintCapstyle(QWidget* parent, int width, Qt::Orientation orientation)
:QWidget(parent), container(3, orientation, "Cap Style", this) {
	setFixedWidth(width);
	
	QRadioButton *flat, *square, *round;
	//Used to map signals to one slot
	QSignalMapper *signalMapper = new QSignalMapper(this);
	
	flat = new QRadioButton("Flat", container);
	signalMapper->setMapping(flat, "flat");
	QObject::connect(flat, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	square = new QRadioButton("Square", container);
	signalMapper->setMapping(square, "square");
	QObject::connect(square, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	round = new QRadioButton("Round", container);
	signalMapper->setMapping(round, "round");
	QObject::connect(round, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	QObject::connect(signalMapper, SIGNAL(mapped(QString)),
		this, SLOT(selectorValueChanged(QString)));
}

PaintCapstyle::~PaintCapstyle() {
}

void PaintCapstyle::selectorValueChanged(QString v) {
	if(v == "flat") {
		emit valueChanged(Qt::FlatCap);
	}
	else if(v == "square") {
		emit valueChanged(Qt::SquareCap);
	}
	else {
		emit valueChanged(Qt::RoundCap);
	}
}
