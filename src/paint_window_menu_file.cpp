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

/*
 * OnNewImage
 *
 * slot that handle action when try to new an image
 */
void PaintMainWindow::OnNewImage() {
}

/*
 * OnLoadImage
 *
 * slot that handle action when try to load an image
 */
void PaintMainWindow::OnLoadImage() {
}

/*
 * OnSaveImage
 *
 * slot that handle action when try to save an image
 */
void PaintMainWindow::OnSaveImage() {
}

/*
 * ChangeFGColor
 *
 * slot that handle action when try to change foreground color
 */
void PaintMainWindow::ChangeFGColor() {
}

/*
 * ChangeBGColor
 *
 * slot that handle action when try to change background color
 */
void PaintMainWindow::ChangeBGColor() {
}

/*
 * OnExit
 *
 * slot that handle action when try to exit
 */
void PaintMainWindow::OnExit() {
	qApp->quit();
}
