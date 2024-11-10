QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32: LIBS += -L$$PWD/../untitled12/build/Desktop_Qt_6_8_0_MSVC2022_64bit-Debug/debug/ -luntitled12

INCLUDEPATH += $$PWD/../untitled12
DEPENDPATH += $$PWD/../untitled12

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../untitled12/build/Desktop_Qt_6_8_0_MSVC2022_64bit-Debug/debug/untitled12.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../untitled12/build/Desktop_Qt_6_8_0_MSVC2022_64bit-Debug/debug/libuntitled12.a
