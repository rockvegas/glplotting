#include "plottingthread.h"

int _threadMain();
//extern HWND gPlottingCanvas;

PlottingThread::PlottingThread()
    : QThread(NULL)
{
    setObjectName("Plotting thread");
}

PlottingThread *PlottingThread::Instance()
{
    static PlottingThread s_instance;
    return &s_instance;
}

PlottingThread::~PlottingThread()
{

}

void PlottingThread::OnPeriodicPlotting()
{
//    PostMessage(gPlottingCanvas, WM_PERIODIC_TIMER, 0, 0);
}

void PlottingThread::OnSubThreadPlotting()
{
    emit Signal_SubThreadPlotting();
}

void PlottingThread::OpenPopup(const QRect &popUpRect)
{
//    QRect* copy = new QRect(popUpRect.left(), popUpRect.top(), popUpRect.width(), popUpRect.height());
//    PostMessage(gPlottingCanvas, WM_POPUP, ((WPARAM)copy), 0);
}

void PlottingThread::ClosePopup(QWidget *popUp)
{
//    PostMessage(gPlottingCanvas, WM_POPUP, ((WPARAM)&(popUp->geometry())), 1);
}

void PlottingThread::Paint()
{
    if (!m_canvas.isNull())
    {
//        PostMessage(gPlottingCanvas, WM_PLOTTING, 0, 0);
    }
}

QPixmap &PlottingThread::GetCanvas()
{
    return m_canvas;
}

void PlottingThread::Slot_OnTimeout()
{
//    static int s_plottingX = 0;
//    if(!m_canvas.isNull())
//    {
//        int plottingY = 10;
//        QPainter painter(&m_canvas);
//        QPen pen(Qt::green);
//        painter.setPen(pen);
//        painter.setCompositionMode(QPainter::CompositionMode_Source);
//        painter.fillRect(s_plottingX, 0, 10, 600, Qt::transparent);
//        for(int i = 0; i < 60; i++)
//        {
//            plottingY = 10 + i * 10;
//            painter.drawLine(s_plottingX, plottingY, s_plottingX + 5, plottingY);
//        }
//        s_plottingX += 5;
//        if(s_plottingX > 800)
//        {
//            s_plottingX = 0;
//        }

////        m_canvas.save("/Users/yinying/Documents/qt_proj/tt.png");
//    }
    emit Signal_SubThreadPlotting();
}

void PlottingThread::run()
{
    m_canvas = QPixmap(800, 600);
    m_canvas.fill(Qt::transparent);
    m_timer = new QTimer();
    QMetaObject::Connection con = connect(m_timer, SIGNAL(timeout()), SLOT(Slot_OnTimeout()), Qt::DirectConnection);
    Q_ASSERT(con);
    m_timer->start(40);
    exec();
    delete m_timer;
    m_timer = NULL;
}

