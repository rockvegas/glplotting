#include "gleddialog.h"

GLedDialog::GLedDialog(QWidget *parent)
    : QPushButton("This is a dialog", parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    m_glCanvas = new GLedCanvas(this);

    QLabel* label = new QLabel("This is a dialog", this);
    layout->addWidget(label);

    QMetaObject::Connection con = connect(m_glCanvas, SIGNAL(Signal_OnPaint(QPainter*)), this, SLOT(Slot_OnCanvasPaint(QPainter*)), Qt::DirectConnection);
    Q_ASSERT(con);
}

GLedDialog::~GLedDialog()
{

}

void GLedDialog::resizeEvent(QResizeEvent *e)
{
    m_glCanvas->resize(e->size());
    QPushButton::resizeEvent(e);
}

void GLedDialog::Slot_OnCanvasPaint(QPainter *glPainter)
{
    QFont font;
    font.setFamily("Monaco");
    font.setPointSize(60);
    font.setBold(true);
    QPen pen(Qt::red);
    glPainter->save();
    glPainter->setFont(font);
    glPainter->setPen(pen);
    glPainter->drawText(1, 1, width(), height(), 0, "Dialog");
    glPainter->restore();
}


GLedCanvas::GLedCanvas(QWidget *parent)
    : QOpenGLWidget(parent)
{
//    QPalette pal;
//    pal.setBrush(QPalette::Background, Qt::black);
//    setPalette(pal);
    setAutoFillBackground(true);
}

GLedCanvas::~GLedCanvas()
{

}

void GLedCanvas::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
//    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
//    painter.setCompositionMode(QPainter::CompositionMode_Source);
    emit Signal_OnPaint(&painter);
}
