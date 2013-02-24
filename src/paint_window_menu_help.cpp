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
#include <qmessagebox.h>

/*
 * ShowAbout
 *
 * slot that handle action when try to show About info
 */
void PaintMainWindow::ShowAbout() {
	QMessageBox::information( this, "About",
		"COMP2012H Project1 Paint\n"
		"By TAN, Shuhao(20090398)");
}
