QT += widgets

CONFIG += c++17

SOURCES += \
    displayfile.cpp \
    drawarea.cpp \
    main.cpp \
    mainwindow.cpp \
    object.cpp \
    shapes.cpp

HEADERS += \
    displayfile.h \
    drawarea.h \
    mainwindow.h \
    object.h \
    shapes.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Viewer3D_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
