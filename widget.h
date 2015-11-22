#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Tile;
class GlPlottingCanvas;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent*);

protected slots:
    void Slot_OnTileClicked(Tile*);
    void Slot_OnPopupClicked();

private:
    GlPlottingCanvas* m_canvas;
};

#endif // WIDGET_H
