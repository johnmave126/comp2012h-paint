/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_linestyle.h
 *
 * Header file for line style selector, for configuration use
 */

#ifndef _PAINT_LINESTYLE_H
#define _PAINT_LINESTYLE_H

#include "paint_common.h"
#include <qmainwindow.h>
#include <qwidget.h>
#include <qbuttongroup.h>
#include <qstring.h>

class PaintLinestyle: public QWidget {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT
	
	public:
		PaintLinestyle(QWidget* parent = 0, int width = 300);
		~PaintLinestyle();
		
		
	public slots:
		/* receive the line change signal */
		void selectorValueChanged(int);
		
	signals:
		void valueChanged(Qt::PenStyle);
	
	private:
		QButtonGroup container;
};
#endif
