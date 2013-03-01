/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_toolbar.h
 *
 * Header file for toolbar
 */

#ifndef _PAINT_TOOLBAR_H
#define _PAINT_TOOLBAR_H

#include "paint_common.h"
#include "paint_canvas.h"
#include <qmainwindow.h>
#include <qapplication.h>
#include <qtoolbar.h>

class PaintToolBar : public QToolBar {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT
	
	public:
		PaintToolBar(QMainWindow* parent = 0, const char* name = 0, PaintCanvas* canvas = 0);
		~PaintToolBar();
		
	protected:
		/** handle show and hide event to emit signal */
		virtual void showEvent(QShowEvent *);
		virtual void hideEvent(QHideEvent *);
		
};
#endif
