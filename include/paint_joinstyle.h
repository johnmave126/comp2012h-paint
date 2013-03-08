/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_joinstyle.h
 *
 * Header file for join style selector, for configuration use
 */

#ifndef _PAINT_JOINSTYLE_H
#define _PAINT_JOINSTYLE_H

#include "paint_common.h"
#include <qmainwindow.h>
#include <qwidget.h>
#include <qbuttongroup.h>
#include <qstring.h>

class PaintJoinstyle: public QWidget {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT
	
	public:
		PaintJoinstyle(QWidget* parent = 0, int width = 300);
		~PaintJoinstyle();
		
		
	public slots:
		/* receive the cap change signal */
		void selectorValueChanged(int);
		
	signals:
		void valueChanged(Qt::PenJoinStyle);
	
	private:
		QButtonGroup container;
};
#endif
