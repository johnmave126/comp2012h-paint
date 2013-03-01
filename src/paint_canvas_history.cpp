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
	emit undoabilityChanged(Current != ImageHistory.begin());
	emit redoabilityChanged(tmp != ImageHistory.end());
}

void PaintCanvas::forward(QPixmap new_node) {
}
