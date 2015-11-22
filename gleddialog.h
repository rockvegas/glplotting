#ifndef GLEDDIALOG_H
#define GLEDDIALOG_H
#include <QtWidgets>
#include <QOpenGLWidget>

class GLedCanvas : public QOpenGLWidget
{
    Q_OBJECT
public:
    GLedCanvas(QWidget* parent);
    virtual ~GLedCanvas();

protected:
    virtual void paintEvent(QPaintEvent* e);

signals:
    void Signal_OnPaint(QPainter* glPainter);
};

class GLedDialog : public QPushButton
{
    Q_OBJECT
public:
    explicit GLedDialog(QWidget* parent);
    virtual ~GLedDialog();

protected:
    virtual void resizeEvent(QResizeEvent* e);

protected slots:
    virtual void Slot_OnCanvasPaint(QPainter* glPainter);

private:
    GLedCanvas* m_glCanvas;
};

#endif // GLEDDIALOG_H
