/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_window_menu_file.cpp
 *
 * The File menu for window
 */
 
 #include "paint_window.h"
#include <qmainwindow.h>
#include <qapplication.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qinputdialog.h>
#include <qfiledialog.h>

void PaintMainWindow::OnNewImage() {
	bool ok;
	int w, h;
	//Ask for width
	w = QInputDialog::getInteger("New Image", "Enter the bitmap width",
			400, 0, 2147483647, 1, &ok, this);
	if(w > 0 && ok) {
		//Ask for height
		h = QInputDialog::getInteger("New Image", "Enter the bitmap height",
				300, 0, 2147483647, 1, &ok, this);
		
		if(h > 0 && ok) {
			//Pass to canvas
			canvas->changeImage(w, h);
		}
	}
}

void PaintMainWindow::OnLoadImage() {
	//Prompt a window to get filename
	QString file = QFileDialog::getOpenFileName(QString::null,
		"BMP image (*.bmp);;PNG image (*.png);;JPEG image (*.jpeg *.jpg)", this, 0, "Load image...");
	
	//Something meaningful be input
	if(!file.isNull()) {
		//Ask canvas to change image
		canvas->changeImage(file);
	}
}

void PaintMainWindow::OnSaveImage() {
	//No need to ask if no image exists
	if(!canvas->isLoaded())
		return;
	
	QString format;
	//Prompt a window to get filename to save
	QString file = QFileDialog::getSaveFileName(QString::null,
		"BMP image (*.bmp);;PNG image (*.png);;JPEG image (*.jpeg *.jpg)",
		this, QString::null, "Save image...", &format);
	
	//Something meaningful be input
	if(!file.isNull()) {
		//Ask canvas to change image
		canvas->saveImage(file, format);
	}
}

void PaintMainWindow::ChangeFGColor() {
}

void PaintMainWindow::ChangeBGColor() {
}

void PaintMainWindow::OnExit() {
	qApp->quit();
}
