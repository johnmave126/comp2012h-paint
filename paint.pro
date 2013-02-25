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

RES_INSTALL.target = FORCE
for(dir, RES_DIR) {
RES_INSTALL.commands += cp -r $$(dir)/* $$(DESTDIR);
}
QMAKE_EXTRA_TARGETS += RES_INSTALL