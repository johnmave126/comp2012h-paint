/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_canvas.h
 *
 * Header file for canvas, area to be drawn upon
 */

#ifndef _PAINT_CANVAS_H
#define _PAINT_CANVAS_H

#include "paint_common.h"
#include <qmainwindow.h>
#include <qapplication.h>

class PaintCanvas : public QWidget {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT
	
	public:
		PaintCanvas();
		~PaintCanvas();
	
}
#endif
