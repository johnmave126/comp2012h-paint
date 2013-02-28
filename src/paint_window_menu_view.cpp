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

void PaintMainWindow::ToggleToolBar() {
	if(tools->isVisible()) {
		tools->hide();
	}
	else {
		tools->show();
	}
}
