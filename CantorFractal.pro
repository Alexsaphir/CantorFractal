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
    Doxygen/latex/refman.pdf \
    Rapport/rapport.pdf \
    Rapport/Images/cantor.png \
    Rapport/Images/carpet.png \
    Rapport/Images/courbe.png \
    Rapport/Images/flocon.png \
    Rapport/Images/hata1.png \
    Rapport/Images/hata2.png \
    Rapport/Images/levy.png \
    Rapport/Images/pentakun.png \
    Rapport/Images/triangle.png \
    Rapport/projet.tex \
    Rapport/rapport.tex \
    Rapport/buffer
