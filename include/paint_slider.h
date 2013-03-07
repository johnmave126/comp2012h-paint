/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_slider.h
 *
 * Header file for general slider, for configuration use
 */

#ifndef _PAINT_SLIDER_H
#define _PAINT_SLIDER_H

#include "paint_common.h"
#include <qmainwindow.h>
#include <qwidget.h>
#include <qlabel.h>
#include <qslider.h>

class PaintSlider: public QWidget {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT
	
	public:
		PaintSlider(QMainWindow* parent = 0, int width = 200, const char* caption = 0);
		~PaintSlider();
		
	public slots:
		/* receive the slide change signal */
		void sliderValueChanged(int);
		
	signals:
		void valueChanged(int);
	
	private:
		QLabel title;
		QSlider slider;
};
#endif
