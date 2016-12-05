#include "pdfcanvas.h"


pdfcanvas::pdfcanvas()
{
    QString filename;
    filename = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/test.pdf";
    m_document = Poppler::Document::load(filename);
    m_document->setRenderHint(Poppler::Document::Antialiasing);
    m_document->setRenderHint(Poppler::Document::TextAntialiasing);
    int index = 0;
    m_pdfPage = m_document->page(index);  // Document starts at page 0
}

pdfcanvas::~pdfcanvas()
{
    delete m_document;

}
void pdfcanvas::paintEvent(QPaintEvent *e)
{
    QPainter* painter = new QPainter(this);
    m_pdfPage = m_document->page(0);
    QSize size = m_pdfPage->pageSize();
    QImage image1 = m_pdfPage->renderToImage(72, 72, 0, 0, size.width(), size.height());
    painter->drawImage(0,0,image1);

    m_pdfPage = m_document->page(1);
    QImage image2 = m_pdfPage->renderToImage(72, 72, 0, 0, size.width(), size.height());
    painter->drawImage(0, size.height(), image2);

}
