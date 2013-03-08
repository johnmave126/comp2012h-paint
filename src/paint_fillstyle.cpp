/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_fillstyle.cpp
 *
 * Draw type config, configuring capstyle
 */

#include "paint_drawtype.h"
#include <qapplication.h>
#include <qstring.h>
#include <qwidget.h>
#include <qdialog.h>
#include <qsignalmapper.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>

PaintFillstyle::PaintFillstyle(QWidget* parent, int width)
:QWidget(parent), container(5, Qt::Horizontal, "Fill Style", this) {
	setFixedSize(width, 100);
	
	//Set margin
	container.setFixedSize(width - 20, 100);
	container.move(10, 0);
	
	//Set exclusive
	container.setExclusive(true);
	
	QRadioButton *solid, *d1, *d2, *d3, *d4, *d5, *d6
		*d7, *hor, *ver, *cross, *bd, *fd, *dc, *nb;
	//Used to map signals to one slot
	QSignalMapper *signalMapper = new QSignalMapper(this);
	
	solid = new QRadioButton("Solid", &container);
	signalMapper->setMapping(solid, 0);
	QObject::connect(solid, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	d1 = new QRadioButton("Dense 1", &container);
	signalMapper->setMapping(d1, 1);
	QObject::connect(d1, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	d2 = new QRadioButton("Dense 2", &container);
	signalMapper->setMapping(d2, 2);
	QObject::connect(d2, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	d3 = new QRadioButton("Dense 3", &container);
	signalMapper->setMapping(d3, 3);
	QObject::connect(d3, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	d4 = new QRadioButton("Dense 4", &container);
	signalMapper->setMapping(d4, 4);
	QObject::connect(d4, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	d5 = new QRadioButton("Dense 5", &container);
	signalMapper->setMapping(d5, 5);
	QObject::connect(d5, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	d6 = new QRadioButton("Dense 6", &container);
	signalMapper->setMapping(d6, 6);
	QObject::connect(d6, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	d7 = new QRadioButton("Dense 7", &container);
	signalMapper->setMapping(d7, 7);
	QObject::connect(d7, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	hor = new QRadioButton("Horizontal", &container);
	signalMapper->setMapping(hor, 8);
	QObject::connect(hor, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	ver = new QRadioButton("Vertical", &container);
	signalMapper->setMapping(ver, 9);
	QObject::connect(ver, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	cross = new QRadioButton("Cross", &container);
	signalMapper->setMapping(cross, 10);
	QObject::connect(cross, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	bd = new QRadioButton("B. Diag", &container);
	signalMapper->setMapping(bd, 11);
	QObject::connect(bd, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	fd = new QRadioButton("F. Diag", &container);
	signalMapper->setMapping(fd, 12);
	QObject::connect(fd, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	dc = new QRadioButton("C. Diag", &container);
	signalMapper->setMapping(dc, 13);
	QObject::connect(dc, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	nb = new QRadioButton("No Pattern", &container);
	//Default
	nb->setChecked(true);
	signalMapper->setMapping(nb, 14);
	QObject::connect(nb, SIGNAL(clicked()),
		signalMapper, SLOT(map()));
	
	QObject::connect(signalMapper, SIGNAL(mapped(int)),
		this, SLOT(selectorValueChanged(int)));
}

PaintFillstyle::~PaintFillstyle() {
}

void PaintFillstyle::selectorValueChanged(int v) {
	switch(v) {
		case 0:
			emit valueChanged(Qt::SolidPattern);
			break;
		case 1:
			emit valueChanged(Qt::Dense1Pattern);
			break;
		case 2:
			emit valueChanged(Qt::Dense2Pattern);
			break;
		case 3:
			emit valueChanged(Qt::Dense3Pattern);
			break;
		case 4:
			emit valueChanged(Qt::Dense4Pattern);
			break;
		case 5:
			emit valueChanged(Qt::Dense5Pattern);
			break;
		case 6:
			emit valueChanged(Qt::Dense6Pattern);
			break;
		case 7:
			emit valueChanged(Qt::Dense7Pattern);
			break;
		case 8:
			emit valueChanged(Qt::HorPattern);
			break;
		case 9:
			emit valueChanged(Qt::VerPattern);
			break;
		case 10:
			emit valueChanged(Qt::CrossPattern);
			break;
		case 11:
			emit valueChanged(Qt::BDiagPattern);
			break;
		case 12:
			emit valueChanged(Qt::FDiagPattern);
			break;
		case 13:
			emit valueChanged(Qt::DiagCrossPattern);
			break;
		case 14:
			emit valueChanged(Qt::NoBrush);
			break;
	}
}
