/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_rect.h
 *
 * Header file for rect, a basic tool to draw
 */

#ifndef _PAINT_RECT_H
#define _PAINT_RECT_H

#include "paint_common.h"
#include "paint_tool.h"
#include <qapplication.h>
#include <qpixmap.h>
#include <qpainter.h>

class PaintRect: public PaintTool {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT
	
	public:
		PaintRect(QMainWindow* parent = 0);
		virtual ~PaintRect();
		
	public slots:
		/*
		 * begin
		 *
		 * dst: the Pixmap to draw upon
		 * fcolor: the foreground color of the rect tool
		 * bcolor: the background color of the rect tool
		 * newPoint: the first point triggered
		 *
		 * return a QPixmap for temporary use
		 *
		 * Initialize the rect tool
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
		 * End the draw of rect tool
		 */
		virtual QPixmap end();
		
		/*
		 * config
		 *
		 * Configure the rect tool
		 */
		virtual void config();
		
		/*
		 * setPenWidth
		 *
		 * r: the border width to set
		 *
		 * set the border width to r
		 */
		void setPenWidth(int r);
		
	private:
		
		//Record last point
		QPoint start_point;
		
		//Fill mode config
		PaintRectFill fill_mode;
};

#endif
