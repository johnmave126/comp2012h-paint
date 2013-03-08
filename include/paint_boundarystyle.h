/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_boundarystyle.h
 *
 * Header file for boundary style selector, for configuration use
 */

#ifndef _PAINT_BOUNDARYSTYLE_H
#define _PAINT_BOUNDARYSTYLE_H

#include "paint_common.h"
#include <qmainwindow.h>
#include <qwidget.h>
#include <qbuttongroup.h>
#include <qstring.h>

class PaintBoundarystyle: public QWidget {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT
	
	public:
		PaintBoundarystyle(QWidget* parent = 0, int width = 300);
		~PaintBoundarystyle();
		
	public slots:
		/* receive the line change signal */
		void selectorValueChanged(int);
		
	signals:
		void valueChanged(Qt::PenStyle);
	
	private:
		QButtonGroup container;
};
#endif
