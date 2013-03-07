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

PaintSlider::PaintSlider(QWidget* parent, int width, const char* caption)
:QWidget(parent), title(caption, this), slider(Qt::Horizontal, this),
 sliderValue(QString("%1").arg(0), this) {
	setFixedSize(width, slider.height());
	title.setFixedWidth(70);
	title.move(10, 0);
	slider.setFixedWidth(width - 130);
	slider.move(100, 0);
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
	sliderValue.setText(QString("%1").arg(r));
	emit valueChanged(r);
}
