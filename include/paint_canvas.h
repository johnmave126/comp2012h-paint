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
	
	protected:
		
		/* paint event handler */
		virtual void paintEvent(QPaintEvent*);
	
	private:
		//History component
		list<QPixmap> ImageHistory;
		list<QPixmap>::iterator Current;
		
		//Foreground color and background color
		QColor fgColor, bgColor;
};
#endif
