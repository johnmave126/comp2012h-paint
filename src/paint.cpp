/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint.cpp
 *
 * The entry for the program
*/

#include <qapplication.h>
#include "paint_widget.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	QWidget* w = new PaintMainWindow();
	a.setMainWidget(w);
	w->show();
	return a.exec();
};
