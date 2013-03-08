/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_capstyle.h
 *
 * Header file for cap style selector, for configuration use
 */

#ifndef _PAINT_CAPSTYLE_H
#define _PAINT_CAPSTYLE_H

#include "paint_common.h"
#include <qmainwindow.h>
#include <qwidget.h>
#include <qgroupbox.h>
#include <qstring.h>

class PaintCapstyle: public QWidget {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT
	
	public:
		PaintCapstyle(QWidget* parent = 0, int width = 300, Qt::Orientation orientation = Qt::Horizontal);
		~PaintCapstyle();
		
		
	public slots:
		/* receive the cap change signal */
		void selectorValueChanged(int);
		
	signals:
		void valueChanged(Qt::PenCapStyle);
	
	private:
		QGroupBox container;
};
#endif
