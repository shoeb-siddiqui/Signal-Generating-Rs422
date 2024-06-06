#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "qwt.h"
#include "qwt_plot.h"
#include "qwt_plot_item.h"
#include "qwt_plot_curve.h"
#include"qwt_legend.h"
#include"qwt_plot_grid.h"
#include"qwt_series_data.h"
#include"samplingthread.h"
#include"plot.h"
#include <qwt_plot_canvas.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_zoomer.h>
#include <qwt_symbol.h>
#include <qwt_text.h>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void creategraphs();
    void SetGraph();

    Plot *plot_1;
    samplingthread *sampling_thread;
    QTimer *DisplayTimer;
    QPointF input;
    QVector<QPointF> inputvector;
    QPointF output,CRC;
    QVector<QPointF> outputvector,CRCvector;
    int waveno;



private slots:
    void Display();

    void on_actionstart_triggered();

    void on_actionstop_triggered();

    void on_actionSINEWAVE_triggered();

    void on_actionSTEPAUTO_triggered();

    void on_actionSTEPMANUAL_triggered();

    void on_actionRAMP_triggered();

    void on_actionTRIANGLE_triggered();

    void on_actionSAWTOOTH_triggered();

    void on_actionSQUARE_triggered();

    void on_actionSTALLFORCETEST_triggered();

    void on_actionpSTEPAUTO_triggered();

    void on_actionnSTEPAUTO_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
