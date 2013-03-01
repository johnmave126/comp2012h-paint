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
	repaint();
	emit undoabilityChanged(true);
	emit redoabilityChanged(tmp != ImageHistory.end());
}

void PaintCanvas::forward(QPixmap new_node) {
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
	
	//Repaint and emit signal
	repaint();
	emit undoabilityChanged(true);
	emit redoabilityChanged(false);
}
