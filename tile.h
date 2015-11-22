#ifndef TILE_H
#define TILE_H

#include <QWidget>

class Tile : public QWidget
{
    Q_OBJECT
public:
    explicit Tile(QWidget *parent = 0);
    virtual ~Tile();

protected:
    virtual void paintEvent(QPaintEvent* e);
    virtual void mousePressEvent(QMouseEvent* e);

signals:
    void Signal_TileClicked(Tile* tile);

public slots:
};

#endif // TILE_H
