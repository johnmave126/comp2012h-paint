/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_window_menu_edit.cpp
 *
 * The Edit menu for window
 */
 
#include "paint_window.h"
#include <qmainwindow.h>
#include <qapplication.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qinputdialog.h>

void PaintMainWindow::OnResizeImage() {
	bool ok;
	int w, h;
	//Do nothing if no image exists
	if(!canvas->isLoaded())
		return;
	
	//Ask for width
	w = QInputDialog::getInteger("Resize Image", "Enter the bitmap width",
			canvas->width(), 0, 2147483647, 1, &ok, this);
	if(w > 0 && ok) {
		//Ask for height
		h = QInputDialog::getInteger("Resize Image", "Enter the bitmap height",
				canvas->height(), 0, 2147483647, 1, &ok, this);
		
		if(h > 0 && ok) {
			//Pass to canvas
			canvas->resizeImage(w, h);
		}
	}
}
