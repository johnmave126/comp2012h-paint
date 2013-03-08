/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_linemode.h
 *
 * Header file for line mode selector, for configuration use
 */

#ifndef _PAINT_LINEMODE_H
#define _PAINT_LINEMODE_H

#include "paint_common.h"
#include <qmainwindow.h>
#include <qwidget.h>
#include <qbuttongroup.h>
#include <qstring.h>

class PaintLinemode: public QWidget {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT
	
	public:
		PaintLinemode(QWidget* parent = 0, int width = 300);
		~PaintLinemode();
		
		
	public slots:
		/* receive the cap change signal */
		void selectorValueChanged(int);
		
	signals:
		void valueChanged(PaintLineMode);
	
	private:
		QButtonGroup container;
};
#endif
