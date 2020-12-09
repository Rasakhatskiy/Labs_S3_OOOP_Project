QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    'src/main.cpp' \
    src/Model/model.cpp \
    src/forms/CropAudio/cropaudio.cpp \
    src/forms/MainWindow/startwindow.cpp

HEADERS += \
    src/Model/model.hpp \
    src/forms/CropAudio/cropaudio.hpp \
    src/forms/MainWindow/startwindow.hpp

FORMS += \
    src/forms/CropAudio/cropaudio.ui \
    src/forms/MainWindow/startwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    src/forms/stylesheet.qss

RESOURCES += \
    src/resources.qrc
