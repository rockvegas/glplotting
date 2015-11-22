#include "widget.h"
#include <QApplication>
#include "plottingthread.h"
#include "glplottingcanvas.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QSurfaceFormat format;
//    format.setDepthBufferSize(24);
//    format.setStencilBufferSize(8);
//    format.setVersion(3, 2);
//    format.setProfile(QSurfaceFormat::CoreProfile);
//    QSurfaceFormat::setDefaultFormat(format);

    Widget w;
    w.show();

    PlottingThread::Instance()->start();

    return a.exec();
}
