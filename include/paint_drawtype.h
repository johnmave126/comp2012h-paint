/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_drawtype.h
 *
 * Header file for draw type selector, for configuration use
 */

#ifndef _PAINT_DRAWTYPE_H
#define _PAINT_DRAWTYPE_H

#include "paint_common.h"
#include <qmainwindow.h>
#include <qwidget.h>
#include <qbuttongroup.h>
#include <qstring.h>

class PaintDrawtype: public QWidget {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT
	
	public:
		PaintDrawtype(QWidget* parent = 0, int width = 300);
		~PaintDrawtype();
		
		
	public slots:
		/* receive the cap change signal */
		void selectorValueChanged(int);
		
	signals:
		void valueChanged(PaintDrawType);
	
	private:
		QButtonGroup container;
};
#endif
