QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Command/Command.cpp \
    Course/Course.cpp \
    Database/Database.cpp \
    Engineering/CompE/CompE.cpp \
    Engineering/Engineering.cpp \
    Semester/Semester.cpp \
    Student/Student.cpp \
    addpopup.cpp \
    changepop.cpp \
    comminterface.cpp \
    main.cpp \
    mainwindow.cpp \
    notepopup.cpp \
    popsearch.cpp \
    removepopup.cpp \
    save_pop_up.cpp

HEADERS += \
    Command/Command.h \
    Course/Course.h \
    Database/Database.h \
    Engineering/CompE/CompE.h \
    Engineering/Engineering.h \
    Semester/Semester.h \
    Student/Student.h \
    addpopup.h \
    changepop.h \
    comminterface.h \
    mainwindow.h \
    notepopup.h \
    popsearch.h \
    removepopup.h \
    save_pop_up.h

FORMS += \
    PopSearch.ui \
    addpopup.ui \
    changepop.ui \
    comminterface.ui \
    mainwindow.ui \
    notepopup.ui \
    popsearch.ui \
    removepopup.ui \
    save_pop_up.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    CE_Data.txt \
    CEreq.txt \
    CEtech.txt \
    cecourses.txt \
    compi.txt \
    course_database.txt \
    gened.txt \
    txt files/CE_Data.txt \
    txt files/CEreq.txt \
    txt files/CEtech.txt \
    txt files/cecourses.txt \
    txt files/compi.txt \
    txt files/compilecommand.txt \
    txt files/course_database.txt \
    txt files/cscourses.txt \
    txt files/ececscourses.txt \
    txt files/eecourses.txt \
    txt files/gened.txt \
    txt files/makefile
