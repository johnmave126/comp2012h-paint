/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_slider.cpp
 *
 * Slider, a basic component to configuration
 */

#include "paint_slider.h"
#include <qapplication.h>
#include <qstring.h>
#include <qwidget.h>
#include <qpainter.h>
#include <qdialog.h>
#include <iostream>
using namespace std;

PaintSlider::PaintSlider(QWidget* parent, int width, const char* caption)
:QWidget(parent), title(caption, this), slider(Qt::Horizontal, this),
 sliderValue(QString(0), this) {
	setFixedWidth(width);
	title.setFixedWidth(40);
	slider.setFixedWidth(width - 40);
	slider.move(40, 0);
	sliderValue.setFixedWidth(30);
	sliderValue.move(width - 30, 0);
	QObject::connect(&slider, SIGNAL(valueChanged(int)),
		this, SLOT(sliderValueChanged(int)));
}

PaintSlider::~PaintSlider() {
}

void PaintSlider::setMin(int m) {
	slider.setMinValue(m);
}

void PaintSlider::setMax(int m) {
	slider.setMaxValue(m);
}

void PaintSlider::sliderValueChanged(int r) {
	sliderValue.setText(r);
	emit valueChanged(r);
}
