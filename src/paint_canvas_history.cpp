/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_canvas_history.cpp
 *
 * Handle affairs related to history operations
 */

#include "paint_canvas.h"
#include <qmainwindow.h>
#include <qwidget.h>
#include <qapplication.h>
#include <qpixmap.h>

#include <list>
using namespace std;

void PaintCanvas::undo() {
	//If now is begin, or no image loaded
	//Do nothing
	if(ImageHistory.empty() || Current == ImageHistory.begin()) {
		return;
	}
	
	//Undo, repaint and emit signal
	Current--;
	buffer = *Current;
	repaint();
	emit undoabilityChanged(Current != ImageHistory.begin());
	emit redoabilityChanged(true);
}

void PaintCanvas::redo() {
	//Create a copy of Current->next
	list<QPixmap>::iterator tmp = Current;
	tmp++;
	
	//If now is end, or no image loaded
	//Do nothing
	if(ImageHistory.empty() || tmp == ImageHistory.end()) {
		return;
	}
	
	//Redo, repaint and emit signal
	Current++;
	tmp++;
	buffer = *Current;
	repaint();
	emit undoabilityChanged(true);
	emit redoabilityChanged(tmp != ImageHistory.end());
}

void PaintCanvas::forward(QPixmap new_node) {
	if(new_node.isNull()) {
		//Null pixmap
		//Do nothing
		return;
	}
	
	//Create a copy of Current->next
	list<QPixmap>::iterator tmp = Current;
	tmp++;
	
	//Erase redo history
	ImageHistory.erase(tmp, ImageHistory.end());
	ImageHistory.insert(ImageHistory.end(), new_node);
	
	//Forward the history
	Current++;
	
	//Remove the first element in history if necessary
	while(ImageHistory.size() > MAX_HISTORY) {
		ImageHistory.erase(ImageHistory.begin());
	}
	buffer = *Current;
	
	//Repaint and emit signal
	repaint();
	emit undoabilityChanged(true);
	emit redoabilityChanged(false);
}

void PaintCanvas::fallback() {
	//Create a copy of Current->next
	list<QPixmap>::iterator tmp = Current;
	tmp++;
	
	//Not last one, not able to fallback
	if(tmp != ImageHistory.end())
		return;
	
	//The first one, not able to fallback
	if(Current == ImageHistory.begin())
		return;
	
	//Store the new last one
	tmp = Current;
	Current--;
	
	//Remove the element
	ImageHistory.erase(tmp);
	buffer = *Current;
	
	//Repaint and emit signal
	repaint();
	emit undoabilityChanged(Current != ImageHistory.begin());
	emit redoabilityChanged(false);
}
