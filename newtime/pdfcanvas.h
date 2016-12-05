#ifndef PDFCANVAS_H
#define PDFCANVAS_H

#include <QStandardPaths>
#include <QWidget>
#include <QPalette>
#include <QDesktopWidget>
#include <QPainter>
#include <QScrollArea>
#include "poppler/poppler-qt5.h"

class pdfcanvas : public QWidget
{
    Q_OBJECT

public:
    pdfcanvas();
    ~pdfcanvas();

public:
    Poppler::Page*       m_pdfPage;
    Poppler::Document*   m_document;

public:
    void paintEvent(QPaintEvent *e);

};

#endif // PDFCANVAS_H
