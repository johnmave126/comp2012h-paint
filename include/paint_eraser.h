/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_eraser.h
 *
 * Header file for eraser, a basic tool to be draw
 */

#ifndef _PAINT_ERASER_H
#define _PAINT_ERASER_H

#include "paint_common.h"
#include "paint_tool.h"
#include <qapplication.h>
#include <qpixmap.h>
#include <qpainter.h>

class PaintEraser: public PaintTool {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT
	
	public:
		PaintEraser(QMainWindow* parent = 0);
		virtual ~PaintEraser();
		
	public slots:
		/*
		 * begin
		 *
		 * dst: the Pixmap to draw upon
		 * fcolor: not used
		 * bcolor: the background color of the pen
		 * newPoint: the first point triggered
		 *
		 * return a QPixmap for temporary use
		 *
		 * Initialize the eraser tool
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
		 * End the draw of eraser
		 */
		virtual QPixmap end();
		
		/*
		 * config
		 *
		 * Configure the eraser
		 */
		virtual void config();
		
		/*
		 * setEraserWidth
		 *
		 * r: the eraser width to set
		 *
		 * set the eraser width to r
		 */
		void setEraserWidth(int r);
		
	private:
		//Configuration
		int width;
};

#endif
