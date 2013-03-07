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
#include "paint_pen.h"
#include "paint_line.h"
#include "paint_rect.h"
#include "paint_eraser.h"
#include <qmainwindow.h>
#include <qapplication.h>
#include <qpixmap.h>
#include <qcolor.h>
#include <list>
using namespace std;

#define MAX_HISTORY 10

class PaintCanvas : public QWidget {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT
	
	public:
		PaintCanvas();
		~PaintCanvas();
		
		/*
		 * changeImage
		 *
		 * w: the width of new image
		 * h: the height of new image
		 *
		 * change the current image to a new image with current
		 * foreground color
		 */
		void changeImage(const int w, const int h);
		
		/*
		 * changeImage
		 *
		 * fileName: the file to be loaded as image
		 *
		 * change the current image to an existed image
		 */
		void changeImage(const QString fileName);
		
		/*
		 * resizeImage
		 *
		 * w: the width of new image
		 * h: the height of new image
		 *
		 * resize the current image to a new size
		 */
		void resizeImage(const int w, const int h);
		
		/*
		 * saveImage
		 *
		 * fileName: the file to be saved as image
		 * filter: the filter selected to save as
		 *
		 * save the current image to a file
		 */
		void saveImage(QString fileName, const QString filter);
		
		
		//Helper functions
		/*
		 * isLoaded
		 *
		 * return true if the canvas has an image in it
		 */
		bool isLoaded();
		
		/*
		 * getFGColor
		 *
		 * return the current foreground color
		 */
		QColor getFGColor() const {return fgColor;}
		
		/*
		 * setFGColor
		 *
		 * color: the new color to be set
		 *
		 * set the current foreground color
		 */
		void setFGColor(QColor color) {if(color.isValid())fgColor = color;}
		
		/*
		 * getBGColor
		 *
		 * return the current background color
		 */
		QColor getBGColor() const {return bgColor;}
		
		/*
		 * setBGColor
		 *
		 * color: the new color to be set
		 *
		 * set the current background color
		 */
		void setBGColor(QColor color) {if(color.isValid())bgColor = color;}
		
		/*
		 * toolState
		 *
		 * return the current tool to use
		 */
		PaintToolType toolState() const {return ToolState;}

		
	public slots:
		
		//History related
		/*
		 * undo
		 *
		 * try to undo the last operation
		 */
		void undo();
		 
		/*
		 * redo
		 *
		 * try to redo the last undo
		 */
		void redo();
		 
		/*
		 * forward
		 *
		 * try to forward the current history
		 */
		void forward(QPixmap new_node);
		
		/*
		 * clearAll
		 *
		 * try to clear the image
		 */
		void clearAll();
		
		/*
		 * config
		 *
		 * prompt to configure the current tool
		 */
		void config();
		
		/*
		 * switchTool
		 *
		 * switch the current tool, judge by the signal sender
		 */
		void switchTool();
		
		/*
		 * switchTool
		 *
		 * tool: the tool to switch
		 *  -Pen: pen tool
		 *  -Line: line tool
		 *  -Rect: rect tool
		 *  -Eraser: eraser tool
		 *
		 * switch the current tool, judge by the parameter
		 */
		void switchTool(PaintToolType tool);
		
		/*
		 * resetTool
		 *
		 * Really reset the current tool
		 */
		void resetTool();
		
	signals:
		/*
		 * undoableChanged
		 *
		 * emitted when undoability changed
		 */
		void undoabilityChanged(bool);
		
		/*
		 * redoableChanged
		 *
		 * emitted when redoability changed
		 */
		void redoabilityChanged(bool);
		
	protected:
		
		/* paint event handler */
		virtual void paintEvent(QPaintEvent*);
		
		/* mousepress event handler */
		virtual void mousePressEvent(QMouseEvent*);
		
		/* mousemove event handler */
		virtual void mouseMoveEvent(QMouseEvent*);
		
		/* mousedoubleclick event handler */
		virtual void mouseDoubleClickEvent(QMouseEvent*);
		
		/* mouserelease event handler */
		virtual void mouseReleaseEvent(QMouseEvent*);
	
	private:
		
		/*
		 * fallback
		 *
		 * try to clear the current history node
		 */
		void fallback();
		
		//History component
		list<QPixmap> ImageHistory;
		list<QPixmap>::iterator Current;
		
		//Drawing content
		QPixmap buffer;
		
		//Foreground color and background color
		QColor fgColor, bgColor;
		
		//Tools
		PaintTool *currentTool;
		PaintPen penTool;
		PaintLine lineTool;
		PaintRect rectTool;
		PaintEraser eraserTool;
		PaintToolType ToolState;
};
#endif
