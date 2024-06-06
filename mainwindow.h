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
#include <QString>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QList>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "QtSerialPort/qserialport.h"
#include "QtSerialPort/qserialportinfo.h"


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
    void writedata(double vol_value);
    
    bool writemode = false;

    Plot *plot_1;
    samplingthread *sampling_thread;
    QTimer *DisplayTimer;
    QPointF input;
    QVector<QPointF> inputvector;
    QPointF output,CRC;
    QVector<QPointF> outputvector,CRCvector;
    int waveno;


    struct Settings
    {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
        bool localEchoEnabled;
    };
private slots:


    void openSerialPort();
    void closeSerialPort();
    void readData();
    void fillPortsInfo();


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
    void on_actionclear_triggered();
    void on_pushButton_connect_clicked();
    void on_pushButton_disconnect_clicked();


private:
    Ui::MainWindow *ui;
    QSerialPort *m_serial = nullptr;
    Settings m_currentSettings;
    void updateSettings();
    void availableSerialUpdate();
    void connectionStatusUpdate();
};

#endif // MAINWINDOW_H
