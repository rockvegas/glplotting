#ifndef GLPLOTTINGCANVAS_H
#define GLPLOTTINGCANVAS_H
#include <QtWidgets>

class GlPlottingCanvas : public /*QWidget*/QOpenGLWidget
{
    Q_OBJECT
public:
    GlPlottingCanvas(QWidget* parent);
    virtual ~GlPlottingCanvas();

    void AddPopup(const QRect& rect);
    void RemovePopup(const QRect& rect);

protected:
    virtual void paintEvent(QPaintEvent *);

protected slots:
    void Slot_OnPlotting();
    void Slot_OnSubThreadPlotting();

private:
    QRegion m_popUpRegion;
};

#endif // GLPLOTTINGCANVAS_H
