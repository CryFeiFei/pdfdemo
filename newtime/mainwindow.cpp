#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    Poppler::Page*       m_pdfPage;
    Poppler::Document*   m_document;

    QString filename;

    filename = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/test.pdf";
    m_document = Poppler::Document::load(filename);
    m_document->setRenderHint(Poppler::Document::Antialiasing);
    m_document->setRenderHint(Poppler::Document::TextAntialiasing);
    int index = 0;
    m_pdfPage = m_document->page(index);  // Document starts at page 0

//    QDesktopWidget* desktopWidget = QApplication::desktop();

//    //获取可用桌面大
//    QRect deskRect = desktopWidget->availableGeometry();
//    //获取设备屏幕大小
//    QRect screenRect = desktopWidget->screenGeometry();

//    QScrollArea* scrollArea;
//    scrollArea = new QScrollArea(this);
//    scrollArea->setBackgroundRole(QPalette::Dark);

 //   scrollArea->setWidget(this);

    QSize size = m_pdfPage->pageSize();
    // Generate a QImage of the rendered page
 //   QImage image = m_pdfPage->renderToImage(72,72,0,0,size.width(),size.height());
 //   image.save(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + QString("/22233333.png"), "png");

    m_pscrollarea = new QScrollArea(this);
    m_pscrollarea->resize(size);
    pdfcanvas*   pPDFcannvas = new pdfcanvas(m_pscrollarea);

    int nNum = m_document->numPages();
    pPDFcannvas->resize(size.width(), size.height()*nNum);

    m_pscrollarea->setBackgroundRole(QPalette::Dark);
    m_pscrollarea->setWidget(pPDFcannvas);

    QScrollBar* pScrollBar = m_pscrollarea->verticalScrollBar();
    pScrollBar->setValue(size.height());


}

MainWindow::~MainWindow()
{
  //  delete m_document;

}

void MainWindow::paintEvent(QPaintEvent *e)
{
//    QPainter* painter = new QPainter(this);
//    m_pdfPage = m_document->page(0);
//    QSize size = m_pdfPage->pageSize();
//    QImage image1 = m_pdfPage->renderToImage(72, 72, 0, 0, size.width(), size.height());
//    painter->drawImage(0,0,image1);

//    m_pdfPage = m_document->page(1);
//    QImage image2 = m_pdfPage->renderToImage(72, 72, 0, 0, size.width(), size.height());
//    painter->drawImage(0, size.height(), image1);

}

