/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_fillcolor.h
 *
 * Header file for fill color selector, for configuration use
 */

#ifndef _PAINT_FILLCOLOR_H
#define _PAINT_FILLCOLOR_H

#include "paint_common.h"
#include <qmainwindow.h>
#include <qwidget.h>
#include <qbuttongroup.h>
#include <qstring.h>

class PaintFillcolor: public QWidget {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT
	
	public:
		PaintFillcolor(QWidget* parent = 0, int width = 300);
		~PaintFillcolor();
		
		
	public slots:
		/* receive the cap change signal */
		void selectorValueChanged(int);
		
	signals:
		void valueChanged(PaintRectFill);
	
	private:
		QButtonGroup container;
};
#endif
