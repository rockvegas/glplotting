#ifndef PLOTTINGTHREAD_H
#define PLOTTINGTHREAD_H
#include <QtCore>
#include <QtWidgets>

class PlottingThread : public QThread
{
    Q_OBJECT
private:
    PlottingThread();

public:
    static PlottingThread* Instance();
    virtual ~PlottingThread();

    void OnPeriodicPlotting();
    void OnSubThreadPlotting();
    void OpenPopup(const QRect& popUpRect);
    void ClosePopup(QWidget* popUp);
    void Paint();
    QPixmap& GetCanvas();

signals:
    void Signal_SubThreadPlotting();

protected slots:
    void Slot_OnTimeout();

    // QThread interface
protected:
    void run();

private:
    QPixmap m_canvas;
    QTimer* m_timer;
};

#endif // PLOTTINGTHREAD_H
