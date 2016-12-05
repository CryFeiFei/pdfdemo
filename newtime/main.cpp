#include "mainwindow.h"
#include <QApplication>
#include <QStandardPaths>
#include <QWidget>
#include <QPalette>
#include <QDesktopWidget>
#include "poppler/poppler-qt5.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(595, 842);
    w.show();


    return a.exec();
}
