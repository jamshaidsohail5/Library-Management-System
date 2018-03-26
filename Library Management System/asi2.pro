#-------------------------------------------------
#
# Project created by QtCreator 2016-10-02T15:44:07
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = asi2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    admin.cpp \
    student.cpp \
    book.cpp \
    clerk.cpp \
    date.cpp \
    dvd.cpp \
    libitem.cpp \
    lms.cpp \
    loan.cpp \
    user.cpp \
    lab.cpp \
    singletonlms.cpp \
    mymain.cpp \
    search.cpp \
    issuebook.cpp \
    issuebook1.cpp \
    issuebook2.cpp \
    issuedvd.cpp \
    issuedvd1.cpp \
    issuedvd2.cpp \
    listitems.cpp \
    checkinitem.cpp \
    checkinitemclerk.cpp \
    checkoutitemadmin.cpp \
    checkoutitemclerk.cpp \
    addboroweradmin.cpp \
    addborowerclerk.cpp \
    updateboroweradmin.cpp \
    updateborowerclerk.cpp \
    removeitem.cpp \
    aditem.cpp \
    state.cpp \
    issued.cpp \
    available.cpp \
    onhold.cpp \
    reference.cpp

HEADERS  += mainwindow.h \
    ../Visual Studio 2015/Projects/Lab2/Lab2/student.h \
    ../Visual Studio 2015/Projects/Lab2/Lab2/dvd.h \
    ../Visual Studio 2015/Projects/Lab2/Lab2/date.h \
    ../Visual Studio 2015/Projects/Lab2/Lab2/lms.h \
    user.h \
    student.h \
    loan.h \
    clerk.h \
    admin.h \
    date.h \
    libitem.h \
    book.h \
    dvd.h \
    lms.h \
    lab.h \
    singletonlms.h \
    mymain.h \
    search.h \
    issuebook.h \
    issuebook1.h \
    issuebook2.h \
    issuedvd.h \
    issuedvd1.h \
    issuedvd2.h \
    listitems.h \
    checkinitem.h \
    checkinitemclerk.h \
    checkoutitemadmin.h \
    checkoutitemclerk.h \
    addboroweradmin.h \
    addborowerclerk.h \
    updateboroweradmin.h \
    updateborowerclerk.h \
    removeitem.h \
    aditem.h \
    state.h \
    issued.h \
    available.h \
    onhold.h \
    reference.h

FORMS    += mainwindow.ui \
    mymain.ui \
    search.ui \
    issuebook.ui \
    issuebook1.ui \
    issuebook2.ui \
    issuedvd.ui \
    issuedvd1.ui \
    issuedvd2.ui \
    listitems.ui \
    checkinitem.ui \
    checkinitemclerk.ui \
    checkoutitemadmin.ui \
    checkoutitemclerk.ui \
    addboroweradmin.ui \
    addborowerclerk.ui \
    updateboroweradmin.ui \
    updateborowerclerk.ui \
    removeitem.ui \
    aditem.ui

DISTFILES += \
    AdminForm.ui.qml \
    Admin.qml
