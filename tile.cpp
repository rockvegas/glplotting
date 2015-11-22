#include "tile.h"
#include <QtWidgets>

Tile::Tile(QWidget *parent) : QWidget(parent)
{

}

Tile::~Tile()
{

}

void Tile::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pen(Qt::cyan);
    QFont font;
    font.setFamily("Monaco");
    font.setPointSize(24);
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(2, 2, 30, 30, 0, "120");
}

void Tile::mousePressEvent(QMouseEvent *e)
{
    emit Signal_TileClicked(this);
}

