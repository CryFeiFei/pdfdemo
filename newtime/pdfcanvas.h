#ifndef PDFCANVAS_H
#define PDFCANVAS_H

#include <QStandardPaths>
#include <QWidget>
#include <QPalette>
#include <QDesktopWidget>
#include <QPainter>
#include <QScrollArea>
#include <QScrollBar>
#include "poppler/poppler-qt5.h"

class pdfcanvas : public QWidget
{
    Q_OBJECT

public:
    pdfcanvas(QScrollArea* pscrollarea);
    ~pdfcanvas();

public:
    Poppler::Page*       m_pdfPage;
    Poppler::Document*   m_document;
    QScrollArea* m_pscrollarea;

public:
    void paintEvent(QPaintEvent *e);

public:
    QImage GetImage();
    int getVPos();

};

#endif // PDFCANVAS_H
