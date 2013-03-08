/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_fillstyle.h
 *
 * Header file for fill style selector, for configuration use
 */

#ifndef _PAINT_FILLSTYLE_H
#define _PAINT_FILLSTYLE_H

#include "paint_common.h"
#include <qmainwindow.h>
#include <qwidget.h>
#include <qbuttongroup.h>
#include <qstring.h>

class PaintFillstyle: public QWidget {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT
	
	public:
		PaintFillstyle(QWidget* parent = 0, int width = 300);
		~PaintFillstyle();
		
		
	public slots:
		/* receive the cap change signal */
		void selectorValueChanged(int);
		
	signals:
		void valueChanged(Qt::BrushStyle);
	
	private:
		QButtonGroup container;
};
#endif
