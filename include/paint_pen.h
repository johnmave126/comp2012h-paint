/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_pen.h
 *
 * Header file for pen, a basic tool to be draw
 */

#ifndef _PAINT_PEN_H
#define _PAINT_PEN_H

#include "paint_tool.h"
#include <qapplication.h>
#include <qpixmap.h>
#include <qpainter.h>

class PaintPen: public PaintTool {
	public:
		PaintPen(QMainWindow* parent = 0);
		~PaintPen();
		
		/*
		 * begin
		 *
		 * dst: the Pixmap to draw upon
		 * color: the color of the pen
		 *
		 * Initialize the pen tool
		 */
		virtual QPixmap begin(QPixmap dst, QColor color, QPoint new_point);
		
		/*
		 * addPoint
		 *
		 * point: the coordinate of the point to add
		 *
		 * Draw a point
		 */
		QPixmap addPoint(QPoint point);
		
		/*
		 * end
		 *
		 * End the draw of pen
		 */
		virtual QPixmap end();
		
		/*
		 * config
		 *
		 * Configure the pen
		 */
		virtual void config();
		
	private:
		//Record last point
		QPoint last_point;
};

#endif
