#include "widget.h"
#include "glplottingcanvas.h"
#include <QtWidgets>
#include "tile.h"
#include "gleddialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPalette pal = palette();
    pal.setBrush(QPalette::Background, Qt::darkGray);
    setPalette(pal);
    setAutoFillBackground(true);
    setGeometry(50, 50, 800, 600);

    QVBoxLayout* layout = new QVBoxLayout(this);
    Tile* tile1 = new Tile(this);
    QMetaObject::Connection con = connect(tile1, SIGNAL(Signal_TileClicked(Tile*)), SLOT(Slot_OnTileClicked(Tile*)), Qt::DirectConnection);
    Q_ASSERT(con);
    layout->addWidget(tile1);
    layout->addWidget(new Tile(this));
    layout->addWidget(new Tile(this));
    layout->addWidget(new Tile(this));

    m_canvas = new GlPlottingCanvas(this);
    m_canvas->setGeometry(0, 0, 800, 600);
    m_canvas->setAttribute(Qt::WA_AlwaysStackOnTop);
    m_canvas->setAttribute(Qt::WA_TransparentForMouseEvents);
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen(Qt::blue);
    QFont font;
    font.setPixelSize(50);
    painter.setPen(pen);
    painter.setFont(font);
    painter.drawText(80, 310, "Demo");
}

void Widget::mousePressEvent(QMouseEvent *)
{

}

void Widget::Slot_OnTileClicked(Tile *)
{
    GLedDialog* button = new GLedDialog(this);
    QMetaObject::Connection con = connect(button, SIGNAL(pressed()), this, SLOT(Slot_OnPopupClicked()), Qt::DirectConnection);
    Q_ASSERT(con);
    button->setGeometry(1, 200, 300, 400);
    m_canvas->AddPopup(QRect(1, 200, 300, 400));
    button->show();
}

void Widget::Slot_OnPopupClicked()
{
    QWidget* popUp = static_cast<QWidget*>(sender());
    m_canvas->RemovePopup(popUp->geometry());
    popUp->close();
    delete popUp;
    popUp = NULL;
}
