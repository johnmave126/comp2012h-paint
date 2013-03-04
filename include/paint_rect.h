/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_rect.h
 *
 * Header file for rect, a basic tool to be draw
 */

#ifndef _PAINT_RECT_H
#define _PAINT_RECT_H

#include <qapplication.h>
#include <qpixmap.h>
#include <qpainter.h>

class PaintRect {
	public:
		PaintRect(QMainWindow* parent = 0);
		~PaintRect();
		
		/*
		 * begin
		 *
		 * dst: the Pixmap to draw upon
		 * color: the color of the pen
		 *
		 * Initialize the pen tool
		 */
		void begin(QPixmap *dst, QColor color);
		
		/*
		 * addPoint
		 *
		 * x: the x-coordinate of the point to add
		 * y: the y-coordinate of the point to add
		 *
		 * Draw a point
		 */
		void addPoint(float x, float y);
		
		/*
		 * end
		 *
		 * End the draw of pen
		 */
		void end();
		
	private:
		QPen drawPen;
		
		//Equivalent to parent
		QMainWindow *my_parent;
		
		//Temporary storage of painting target and painter
		QPixmap *my_dst;
		QPainter bufferPainter
};

#endif
