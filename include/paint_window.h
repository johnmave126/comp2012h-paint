/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_window.h
 *
 * The header file for mainwindow of the program
 */

#ifndef _PAINT_WINDOW_H
#define _PAINT_WINDOW_H

#include "paint_common.h"
#include "paint_canvas.h"
#include "paint_toolbar.h"
#include <qmainwindow.h>
#include <qapplication.h>
#include <qscrollview.h>
#include <qtoolbar.h>

class PaintMainWindow: public QMainWindow {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT

	public:
		PaintMainWindow(QWidget* parent = 0, const char* name = 0);
		~PaintMainWindow();
	
	protected:
		
	public slots:
		
		//File Menu Begin
		
		/*
		 * OnNewImage
		 *
		 * slot that handle action when try to new an image
		 */
		void OnNewImage();
		
		/*
		 * OnLoadImage
		 *
		 * slot that handle action when try to load an image
		 */
		void OnLoadImage();
		
		/*
		 * OnSaveImage
		 *
		 * slot that handle action when try to save an image
		 */
		void OnSaveImage();
		
		/*
		 * ChangeFGColor
		 *
		 * slot that handle action when try to change foreground color
		 */
		void ChangeFGColor();
		
		/*
		 * ChangeBGColor
		 *
		 * slot that handle action when try to change background color
		 */
		void ChangeBGColor();
		
		/*
		 * OnExit
		 *
		 * slot that handle action when try to exit
		 */
		void OnExit();
		//File Menu End
		
		//Edit Menu Begin
		
		/*
		 * OnUndo
		 *
		 * slot that handle action when try to undo
		 */
		void OnUndo();
		
		/*
		 * OnRedo
		 *
		 * slot that handle action when try to redo
		 */
		void OnRedo();
		
		/*
		 * OnClearAll
		 *
		 * slot that handle action when try to clear the image
		 */
		void OnClearAll();
		
		/*
		 * OnResizeImage
		 *
		 * slot that handle action when try to resize the image
		 */
		void OnResizeImage();
		//Edit Menu End
		
		//View Menu Begin
		
		/*
		 * ToggleToolBar
		 *
		 * slot that handle action when try to toggle toolbar
		 */
		void ToggleToolBar();
		//View Menu End
		
		//Help Menu Begin
		
		/*
		 * ShowAbout
		 *
		 * slot that handle action when try to show About info
		 */
		void ShowAbout();
		//Help Menu End
	private:
		
		/*
		 * CreateMenuBar
		 *
		 * To create menu bar for window
		 */
		void CreateMenuBar();
		
		QScrollView* viewport;
		PaintCanvas* canvas;
		
		//ToolBar
		QToolBar* tools;
};

#endif
