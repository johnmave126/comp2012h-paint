/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_pen.h
 *
 * Header file for pen, a basic tool to draw
 */

#ifndef _PAINT_PEN_H
#define _PAINT_PEN_H

#include "paint_common.h"
#include "paint_tool.h"
#include <qapplication.h>
#include <qpixmap.h>
#include <qpainter.h>

class PaintPen: public PaintTool {
	public:
		PaintPen(QMainWindow* parent = 0);
		virtual ~PaintPen();
		
	public slots:
		/*
		 * begin
		 *
		 * dst: the Pixmap to draw upon
		 * fcolor: the foreground color of the pen
		 * bcolor: not used
		 * newPoint: the first point triggered
		 *
		 * return a QPixmap for temporary use
		 *
		 * Initialize the pen tool
		 */
		virtual QPixmap begin(QPixmap dst, QColor fColor, QColor bColor, QPoint new_point);
		
		/*
		 * process
		 *
		 * newPoint: the point to process upon mouseEvent
		 *
		 * return a QPixmap for temporary use
		 *
		 * Process a point, used during drawing
		 */
		virtual QPixmap process(QPoint point);
		
		/*
		 * end
		 *
		 * return a QPixmap, which is the final version
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
