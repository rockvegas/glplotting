#include "glplottingcanvas.h"
#include "plottingthread.h"

GlPlottingCanvas::GlPlottingCanvas(QWidget *parent)
    : /*QWidget*/QOpenGLWidget(parent)
{
    QMetaObject::Connection con = connect(PlottingThread::Instance(), SIGNAL(Signal_SubThreadPlotting()), this, SLOT(Slot_OnPlotting()), Qt::QueuedConnection);
    Q_ASSERT(con);
//    con = connect(PlottingThread::Instance(), SIGNAL(Signal_SubThreadPlotting()), this, SLOT(Slot_OnSubThreadPlotting()), Qt::DirectConnection);
//    Q_ASSERT(con);
//    setUpdateBehavior(QOpenGLWidget::NoPartialUpdate);
//    setFormat(QSurfaceFormat::defaultFormat());
}

void GlPlottingCanvas::Slot_OnPlotting()
{
    update();
    //    qDebug() << ".... update";
}

void GlPlottingCanvas::Slot_OnSubThreadPlotting()
{
////    makeCurrent();
//    QOpenGLContext* ctx = context();
//    if(ctx)
//    {
//        ctx->moveToThread(PlottingThread::Instance());
//    }
//    QPainter painter(this);
//    QPixmap& pix = PlottingThread::Instance()->GetCanvas();
////    qDebug() << ".... paint";
//    painter.drawPixmap(0, 0, 800, 600, pix);
////    doneCurrent();
}

GlPlottingCanvas::~GlPlottingCanvas()
{

}

void GlPlottingCanvas::AddPopup(const QRect &rect)
{
    m_popUpRegion += rect;
}

void GlPlottingCanvas::RemovePopup(const QRect &rect)
{
    m_popUpRegion -= rect;
}

void GlPlottingCanvas::paintEvent(QPaintEvent *)
{
//    QPainter painter(this);
//    painter.setCompositionMode(QPainter::CompositionMode_Source);
//    QPixmap& pix = PlottingThread::Instance()->GetCanvas();
////    qDebug() << ".... paint";
//    painter.drawPixmap(0, 0, 800, 600, pix);

    static double s_plottingX = 0;
    double plottingY = 0;
    QPainter painter(this);
    QPen pen(Qt::green);
    painter.setPen(pen);

    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(s_plottingX, 0, 10, 600, Qt::transparent);
    QPainterPath path;
    path.addRegion(m_popUpRegion);
    painter.fillPath(path, Qt::transparent);

    QRegion region(rect());
    region -= m_popUpRegion;
    painter.setClipRegion(region);

    for(int i = 0; i < 60; i++)
    {
        plottingY = 10 + i * 10;
        painter.drawLine(s_plottingX, plottingY, s_plottingX + 5, plottingY);
    }
    s_plottingX += 5;
    if(s_plottingX > 800)
    {
        s_plottingX = 0;
    }
}

