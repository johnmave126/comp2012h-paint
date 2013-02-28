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
#include <qcolordialog.h>

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
	//Do nothing if no image exists
	if(!canvas->isLoaded())
		return;
	
	QString format;
	//Prompt a window to get filename to save
	QString file = QFileDialog::getSaveFileName(QString::null,
		"BMP image (*.bmp);;PNG image (*.png);;JPEG image (*.jpg *.jpeg)",
		this, QString::null, "Save image...", &format);
	
	//Something meaningful be input
	if(!file.isNull()) {
		//Ask canvas to change image
		canvas->saveImage(file, format);
	}
}

void PaintMainWindow::ChangeFGColor() {
	//Prompt a window to get new foreground color
	QColor new_color = QColorDialog::getColor(canvas->getFGColor(), this);
	//Something meaningful be input
	if(new_color.isValid()) {
		//Ask canvas to change foreground color
		canvas->setFGColor(new_color);
	}
}

void PaintMainWindow::ChangeBGColor() {
	//Prompt a window to get new background color
	QColor new_color = QColorDialog::getColor(canvas->getBGColor(), this);
	//Something meaningful be input
	if(new_color.isValid()) {
		//Ask canvas to change background color
		canvas->setBGColor(new_color);
	}
}

void PaintMainWindow::OnExit() {
	qApp->quit();
}
