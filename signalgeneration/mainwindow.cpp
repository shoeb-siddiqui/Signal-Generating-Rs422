#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QThread>
#include <QMessageBox>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sampling_thread = new samplingthread();
    creategraphs();
    DisplayTimer = new QTimer(this);
    connect(DisplayTimer,SIGNAL(timeout()),this,SLOT(Display()));
    sampling_thread->setInterval(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::creategraphs()
{
    SetGraph();
}

void MainWindow::SetGraph()
{
    plot_1 = new Plot();
    ui->gridLayout->addWidget(plot_1);
    plot_1->setTitle("COMMAND_PLOT_WINDOW");


}

void MainWindow::Display()
{
    plot_1->setcurvedata(sampling_thread->inputvector);
}

void MainWindow::on_actionstart_triggered()
{
    sampling_thread->start();
    DisplayTimer->start(15);
}




void MainWindow::on_actionstop_triggered()
{
    sampling_thread->stop();
    DisplayTimer->stop();
}

void MainWindow::on_actionSINEWAVE_triggered()
{
    waveno = 1;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionSTEPAUTO_triggered()
{
    waveno = 2;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionSTEPMANUAL_triggered()
{
    waveno = 3;
    sampling_thread->wave = waveno;
}


void MainWindow::on_actionRAMP_triggered()
{
    waveno = 4;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionTRIANGLE_triggered()
{
    waveno = 5;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionSAWTOOTH_triggered()
{
    waveno = 6;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionSQUARE_triggered()
{
    waveno = 7;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionSTALLFORCETEST_triggered()
{
    waveno = 8;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionpSTEPAUTO_triggered()
{
    waveno = 9;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionnSTEPAUTO_triggered()
{
    waveno = 10;
    sampling_thread->wave = waveno;
}
