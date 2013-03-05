/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_tool.h
 *
 * Header file for PaintTool, base class to all tools
 */

#ifndef _PAINT_TOOL_H
#define _PAINT_TOOL_H

#include <qapplication.h>
#include <qmainwindow.h>
#include <qpixmap.h>
#include <qpainter.h>
#include <qpen.h>

class PaintTool {
	public:
		PaintTool(QMainWindow* parent = 0);
		virtual ~PaintTool();
		
		/*
		 * begin
		 *
		 * dst: the Pixmap to draw upon
		 * color: the color of the tool
		 *
		 * Initialize the tool
		 */
		virtual QPixmap begin(QPixmap dst, QColor color, QPoint new_point) = 0;
		
		/*
		 * end
		 *
		 * End the draw of the tool
		 */
		virtual QPixmap end() = 0;
		
		/*
		 * config
		 *
		 * Prompt to configure the tool
		 */
		virtual void config() = 0;
		
		/*
		 * isBegin
		 *
		 * return if the draw begins
		 */
		bool isBegin();
		
		
	protected:
		QPen drawPen;
		
		//Equivalent to parent
		QMainWindow *my_parent;
		
		//Temporary storage of painting target and painter
		QPixmap my_target;
		QPainter bufferPainter;
};

#endif
