#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QStandardPaths>
#include <QWidget>
#include <QPalette>
#include <QDesktopWidget>
#include <QPainter>
#include <QScrollArea>
#include "poppler/poppler-qt5.h"
#include "pdfcanvas.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    pdfcanvas*  m_pPDFcanvas;
//public:
//    Poppler::Page*       m_pdfPage;
//    Poppler::Document*   m_document;

public:
    void paintEvent(QPaintEvent *e);
};

#endif // MAINWINDOW_H
