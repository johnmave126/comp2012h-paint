TARGET = paint
INCLUDEPATH += include
DEPENDPATH  += include src
HEADERS += paint.h paint_common.h paint_window.h
SOURCES += \
	paint.cpp paint_window.cpp paint_window_menu_edit.cpp \
	paint_window_menu_file.cpp paint_window_menu_help.cpp \
	paint_window_menu_view.cpp
RES_DIR = resource
CONFIG += qt warn_on
DESTDIR = build_bin
MOC_DIR = build_tmp
OBJECTS_DIR = build_tmp


QMAKE_POST_LINK= cp a b
res_install.target = .test
res_install.commands = cp a b
#for(dir, RES_DIR) {
#}
QMAKE_EXTRA_TARGETS += res_install