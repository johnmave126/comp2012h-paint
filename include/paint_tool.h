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
#include <qdialog.h>

class PaintTool: public QObject {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT
	
	public:
		PaintTool(QMainWindow* parent = 0);
		virtual ~PaintTool();
		
	public slots:
		/*
		 * begin
		 *
		 * dst: the Pixmap to draw upon
		 * fcolor: the foreground color of the tool
		 * bcolor: the background color of the tool
		 * newPoint: the first point triggered
		 *
		 * return a QPixmap for temporary use
		 *
		 * Initialize the tool
		 */
		virtual QPixmap begin(QPixmap dst, QColor fcolor, QColor bcolor, QPoint new_point) = 0;
		
		/*
		 * process
		 *
		 * newPoint: the point to process upon mouseEvent
		 *
		 * return a QPixmap for temporary use
		 *
		 * Process a point, used during drawing
		 */
		virtual QPixmap process(QPoint newPoint) = 0;
		
		/*
		 * end
		 *
		 * return a QPixmap, which is the final version
		 *
		 * End the draw of the tool
		 */
		virtual QPixmap end() = 0;
		
		/*
		 * dblEnd
		 *
		 * end function for double click, not many tool will use this
		 */
		virtual void dblEnd();
		
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
		//Pen and brush used
		QPen drawPen;
		QBrush fillBrush;
		
		//Temporary storage of painting target and painter
		QPixmap my_target;
		QPainter bufferPainter;
		
		//Temporary storage of indicator target and painter
		QPixmap tmp_target;
		QPainter tmpBufferPainter;
		
		//Dialog for configuration
		QDialog config_window;
};

#endif
