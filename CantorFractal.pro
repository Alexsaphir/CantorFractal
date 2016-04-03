QT+=widgets gui core printsupport

QMAKE_CXXFLAGS += -Wno-comment
QMAKE_CXXFLAGS += -Wall

SOURCES += \
    main.cpp \
    application.cpp \
    fractale.cpp \
    forme.cpp \
    homothetie.cpp \
    rotation.cpp \
    window.cpp \
    similitudedirecte.cpp \
    similitudeindirecte.cpp \
    windowgenfractale.cpp

HEADERS += \
    application.h \
    fractale.h \
    forme.h \
    homothetie.h \
    rotation.h \
    window.h \
    similitudedirecte.h \
    similitudeindirecte.h \
    windowgenfractale.h

DISTFILES += \
    Triangle \
    TODO \
    HataTreeLike \
    Source \
    Script_Scilab/script.sce \
