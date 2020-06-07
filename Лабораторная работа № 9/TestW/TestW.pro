include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt
INCLUDEPATH += C:\Users\Waytmer\Desktop\Lab9_Project_for_tests
HEADERS += \
        C:/Users/Waytmer/Desktop/Lab9_Project_for_tests/IKeypad.h \
        C:/Users/Waytmer/Desktop/Lab9_Project_for_tests/ILatch.h \
        C:/Users/Waytmer/Desktop/Lab9_Project_for_tests/lockcontroller.h \
        tst_waytmertest.h

SOURCES += \
        C:/Users/Waytmer/Desktop/Lab9_Project_for_tests/lockcontroller.cpp \
        main.cpp
