TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bar.cpp \
        main.cpp \
        pointscounter.cpp \
        solver.cpp \
        trieloader.cpp \
        trienode.cpp

HEADERS += \
    bar.hpp \
    list.hpp \
    pair.hpp \
    pointscounter.hpp \
    solver.hpp \
    trieloader.hpp \
    trienode.hpp
