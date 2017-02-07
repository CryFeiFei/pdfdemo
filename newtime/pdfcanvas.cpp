#include "pdfcanvas.h"


pdfcanvas::pdfcanvas(QScrollArea* pscrollarea)
{
    m_pscrollarea = pscrollarea;
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
//    int nNum = m_document->numPages();
//    m_pdfPage = m_document->page(0);
//    QSize size = m_pdfPage->pageSize();
//    for(int i = 1; i <= 5; ++i)
//    {
//        m_pdfPage = m_document->page(i-1);
//        QImage image1 = m_pdfPage->renderToImage(72, 72, 0, 0, size.width(), size.height());
//        painter->drawImage(0,(i-1)*(size.height()+8),image1);
//    }
    QImage image1 = GetImage();
   painter->drawImage(0, getVPos(),image1);
//    m_pdfPage = m_document->page(0);
//    QImage image1 = m_pdfPage->renderToImage(72, 72, 0, 0, size.width(), size.height());
//    painter->drawImage(0,0,image1);

//    m_pdfPage = m_document->page(1);
//    QImage image2 = m_pdfPage->renderToImage(72, 72, 0, 0, size.width(), size.height());
//    painter->drawImage(0, size.height(), image2);

}

int pdfcanvas::getVPos()
{
    QScrollBar* pScrollBar = m_pscrollarea->verticalScrollBar();
    int npos = pScrollBar->value();
    return npos;
}

QImage pdfcanvas::GetImage()
{
    int vpos = getVPos();

    // 获取第一页的大小
    int nNum = m_document->numPages();
    m_pdfPage = m_document->page(0);
    QSize size = m_pdfPage->pageSize();

    int vhigh = size.height();

    int ny = vpos % vhigh;
    int npagenum = vpos / vhigh;

    m_pdfPage = m_document->page(npagenum);
    QImage image2 = m_pdfPage->renderToImage(72, 72, 0, npagenum, size.width(), size.height());





    return image2;
}
