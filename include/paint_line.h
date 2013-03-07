/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_line.h
 *
 * Header file for line, a basic tool to draw
 */

#ifndef _PAINT_LINE_H
#define _PAINT_LINE_H

#include "paint_common.h"
#include "paint_tool.h"
#include <qapplication.h>
#include <qpixmap.h>
#include <qpainter.h>

class PaintLine: public PaintTool {
	public:
		PaintLine(QMainWindow* parent = 0);
		virtual ~PaintLine();
		
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
		 * Initialize the line tool
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
		 * End the draw of line
		 */
		virtual QPixmap end();
		
		/*
		 * dblEnd
		 *
		 * End the draw of line in polyline mode
		 */
		virtual void dblEnd();
		
		/*
		 * config
		 *
		 * Configure the line
		 */
		virtual void config();
		
		/*
		 * isBegin
		 *
		 * return if the draw begins
		 */
		virtual bool isBegin();
		
	private:
		//Last time point and temporary point storage
		QPoint last_point, tmp_point;
		
		//Current Mode
		PaintLineMode mode;
};

#endif
