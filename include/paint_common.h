/*
 * Paint for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * paint_common.h
 *
 * Common definition inclusion
 */

#ifndef _PAINT_COMMON_H
#define _PAINT_COMMON_H

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef NULL
#define NULL 0
#endif

//Tools
enum PaintToolType {
	Pen = 0,
	Line,
	Rect,
	Eraser
};

//Line Config
enum PaintLineMode {
	Sing = 0,
	Poly
};

//Rect Config
enum PaintRectFill {
	FG = 0,
	BG
};
enum PaintDrawType {
	Rect = 0,
	RRect,
	Circ,
	Elli
};

#endif
