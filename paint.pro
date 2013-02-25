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

res_install.target = FORCE
#for(dir, RES_DIR) {
res_install.commands = cp $${RES_DIR} $${DESTDIR}
#}
QMAKE_EXTRA_TARGETS += res_install