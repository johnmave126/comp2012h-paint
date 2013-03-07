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
#include <qwidget.h>
#include <qpainter.h>
#include <qdialog.h>
#include <iostream>
using namespace std;

PaintSlider::PaintSlider(QWidget* parent, int width, const char* caption)
:QWidget(parent), title(caption, this), slider(Qt::Horizontal, this) {
	setFixedWidth(width);
	title.setFixedWidth(70);
	slider.setFixedWidth(width - 70);
	slider.setGeometry(70, 0, width - 70, slider.height());
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
	emit valueChanged(r);
}
