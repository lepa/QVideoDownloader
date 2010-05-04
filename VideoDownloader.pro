# -------------------------------------------------
# Project created by QtCreator 2010-05-01T19:15:44
# -------------------------------------------------
QT += network
TARGET = VideoDownloader
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    Download/download.cpp \
    VDownloader/vdownloader.cpp \
    VDownloader/Youtube/youtube.cpp \
    VDownloader/Youjizz/youjizz.cpp \
    VDownloader/Youporn/youporn.cpp \
    VDownloader/Megavideo/megavideo.cpp
HEADERS += mainwindow.h \
    Download/download.h \
    VDownloader/vdownloader.h \
    VDownloader/Youtube/youtube.h \
    VDownloader/Youjizz/youjizz.h \
    VDownloader/Youporn/youporn.h \
    VDownloader/Megavideo/megavideo.h
FORMS += mainwindow.ui
