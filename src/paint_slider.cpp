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

PaintSlider::PaintSlider(QWidget* parent, int width, const char* caption)
:QWidget(parent), title(caption, this), slider(this) {
	this.setWidth(width);
	title.setWidth(70);
	slider.setWidth(width - 70);
	QObject::connect(slider, SIGNAL(valueChanged(int)),
		this, SLOT(sliderValueChanged(int)));
}

PaintSlider::~PaintSlider() {
}

void setMin(int m) {
	slider.setMinValue(m);
}

void setMax(int m) {
	slider.setMaxValue(m);
}

void sliderValueChanged(int r) {
	emit valueChanged(r);
}
