#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QThread>
#include <QMessageBox>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_serial(new QSerialPort(this))
{
    ui->setupUi(this);

    // connect(this->m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);

    ui->comboBox_baud_rate->addItem(QStringLiteral("9600"));
    ui->comboBox_baud_rate->itemData(ui->comboBox_baud_rate->count()-1, 0) = QSerialPort::Baud9600;
    ui->comboBox_baud_rate->addItem(QStringLiteral("19200"));
    ui->comboBox_baud_rate->itemData(ui->comboBox_baud_rate->count()-1, 0) = QSerialPort::Baud19200;
    ui->comboBox_baud_rate->addItem(QStringLiteral("38400"));
    ui->comboBox_baud_rate->itemData(ui->comboBox_baud_rate->count()-1, 0) = QSerialPort::Baud38400;
    ui->comboBox_baud_rate->addItem(QStringLiteral("115200"));
    ui->comboBox_baud_rate->itemData(ui->comboBox_baud_rate->count()-1, 0) = QSerialPort::Baud115200;
    ui->comboBox_baud_rate->setCurrentIndex(3);


    ui->comboBox_data_bits->addItem(QStringLiteral("5"));
    ui->comboBox_data_bits->itemData(ui->comboBox_data_bits->count()-1, 0) = QSerialPort::Data5;
    ui->comboBox_data_bits->addItem(QStringLiteral("6"));
    ui->comboBox_data_bits->itemData(ui->comboBox_data_bits->count()-1, 0) = QSerialPort::Data6;
    ui->comboBox_data_bits->addItem(QStringLiteral("7"));
    ui->comboBox_data_bits->itemData(ui->comboBox_data_bits->count()-1, 0) = QSerialPort::Data7;
    ui->comboBox_data_bits->addItem(QStringLiteral("8"));
    ui->comboBox_data_bits->itemData(ui->comboBox_data_bits->count()-1, 0) = QSerialPort::Data8;
    ui->comboBox_data_bits->setCurrentIndex(3);


    ui->comboBox_parity_bit->addItem(tr("None"));
    ui->comboBox_parity_bit->itemData(ui->comboBox_parity_bit->count()-1, 0) = QSerialPort::NoParity;
    ui->comboBox_parity_bit->addItem(tr("Even"));
    ui->comboBox_parity_bit->itemData(ui->comboBox_parity_bit->count()-1, 0) = QSerialPort::EvenParity;
    ui->comboBox_parity_bit->addItem(tr("Odd"));
    ui->comboBox_parity_bit->itemData(ui->comboBox_parity_bit->count()-1, 0) = QSerialPort::OddParity;
    ui->comboBox_parity_bit->addItem(tr("Mark"));
    ui->comboBox_parity_bit->itemData(ui->comboBox_parity_bit->count()-1, 0) = QSerialPort::MarkParity;
    ui->comboBox_parity_bit->addItem(tr("Space"));
    ui->comboBox_parity_bit->itemData(ui->comboBox_parity_bit->count()-1, 0) = QSerialPort::SpaceParity;
    ui->comboBox_parity_bit->setCurrentIndex(0);


    ui->comboBox_stop_bit->addItem(QStringLiteral("1"));
    ui->comboBox_stop_bit->itemData(ui->comboBox_stop_bit->count()-1, 0) = QSerialPort::OneStop;
    ui->comboBox_stop_bit->addItem(tr("1.5"));
    ui->comboBox_stop_bit->itemData(ui->comboBox_stop_bit->count()-1, 0) = QSerialPort::OneAndHalfStop;
    ui->comboBox_stop_bit->addItem(QStringLiteral("2"));
    ui->comboBox_stop_bit->itemData(ui->comboBox_stop_bit->count()-1, 0) = QSerialPort::TwoStop;
    ui->comboBox_stop_bit->setCurrentIndex(0);

    ui->comboBox_flow_control->addItem(tr("None"));
    ui->comboBox_flow_control->itemData(ui->comboBox_flow_control->count()-1, 0) = QSerialPort::NoFlowControl;
    ui->comboBox_flow_control->addItem(tr("RTS/CTS"));
    ui->comboBox_flow_control->itemData(ui->comboBox_flow_control->count()-1, 0) = QSerialPort::HardwareControl;
    ui->comboBox_flow_control->addItem(tr("XON/XOFF"));
    ui->comboBox_flow_control->itemData(ui->comboBox_flow_control->count()-1, 0) = QSerialPort::SoftwareControl;
    ui->comboBox_flow_control->setCurrentIndex(0);


    updateSettings();

    QFuture<void> serial_update_future = QtConcurrent::run(this, &MainWindow::availableSerialUpdate);
    QFuture<void> connection_update_future = QtConcurrent::run(this, &MainWindow::connectionStatusUpdate);


    sampling_thread = new samplingthread();
    creategraphs();
    DisplayTimer = new QTimer(this);
    connect(DisplayTimer,SIGNAL(timeout()),this,SLOT(Display()));
    sampling_thread->setInterval(2);
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

void MainWindow::writedata(double vol_value)
{


    QString data = QString::number(vol_value, 'f', 3);
    m_serial->write(data.toLocal8Bit());


    //    if(m_serial->write(data.toLocal8Bit()) < 0)
    //    {
    //        data += " - FAILED TO SEND";

    //    }
    //    else
    //    {
    //        // qDebug()<<"data in loop 2:  "<<data<<endl;
    //        // ui->plainTextEdit_console->insertPlainText(data);
    //    }

}

void MainWindow::Display()
{

    writedata(sampling_thread->votages);
    plot_1->setcurvedata(sampling_thread->inputvector);
    readData();
    plot_1->setcurvedata1(sampling_thread->outputvector);

}

void MainWindow::on_actionstart_triggered()
{
    sampling_thread->start();
    DisplayTimer->start(20);
}

void MainWindow::on_actionstop_triggered()
{
    sampling_thread->stop();
    DisplayTimer->stop();
}

void MainWindow::on_actionSINEWAVE_triggered()
{
    plot_1->clearcurve(sampling_thread->inputvector);
    plot_1->clearcurve1(sampling_thread->outputvector);


    waveno = 1;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionSTEPAUTO_triggered()
{
    plot_1->clearcurve(sampling_thread->inputvector);
    plot_1->clearcurve1(sampling_thread->outputvector);


    waveno = 2;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionSTEPMANUAL_triggered()
{
    plot_1->clearcurve(sampling_thread->inputvector);
    plot_1->clearcurve1(sampling_thread->outputvector);


    waveno = 3;
    sampling_thread->wave = waveno;
}


void MainWindow::on_actionRAMP_triggered()
{
    plot_1->clearcurve(sampling_thread->inputvector);
    plot_1->clearcurve1(sampling_thread->outputvector);
    waveno = 4;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionTRIANGLE_triggered()
{
    plot_1->clearcurve(sampling_thread->inputvector);
    plot_1->clearcurve1(sampling_thread->outputvector);


    waveno = 5;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionSAWTOOTH_triggered()
{
    plot_1->clearcurve(sampling_thread->inputvector);
    plot_1->clearcurve1(sampling_thread->outputvector);


    waveno = 6;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionSQUARE_triggered()
{
    plot_1->clearcurve(sampling_thread->inputvector);
    plot_1->clearcurve1(sampling_thread->outputvector);
    waveno = 7;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionSTALLFORCETEST_triggered()
{
    plot_1->clearcurve(sampling_thread->inputvector);
    plot_1->clearcurve1(sampling_thread->outputvector);


    waveno = 8;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionpSTEPAUTO_triggered()
{
    plot_1->clearcurve(sampling_thread->inputvector);
    plot_1->clearcurve1(sampling_thread->outputvector);


    waveno = 9;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionnSTEPAUTO_triggered()
{
    plot_1->clearcurve(sampling_thread->inputvector);
    plot_1->clearcurve1(sampling_thread->outputvector);


    waveno = 10;
    sampling_thread->wave = waveno;
}

void MainWindow::on_actionclear_triggered()
{
    plot_1->clearcurve(sampling_thread->inputvector);
    plot_1->clearcurve1(sampling_thread->outputvector);

}
void MainWindow::updateSettings()
{
    this->m_currentSettings.name = ui->comboBox_port_name->itemData(ui->comboBox_port_name->currentIndex(), 0).toString();

    m_currentSettings.baudRate = ui->comboBox_baud_rate->itemData(ui->comboBox_baud_rate->currentIndex(), 0).toInt();
    m_currentSettings.stringBaudRate = QString::number(m_currentSettings.baudRate);

    m_currentSettings.dataBits = static_cast<QSerialPort::DataBits>(
                ui->comboBox_data_bits->itemData(ui->comboBox_data_bits->currentIndex(), 0).toInt());
    m_currentSettings.stringDataBits =  ui->comboBox_data_bits->itemData(ui->comboBox_data_bits->currentIndex(), 0).toString();

    m_currentSettings.parity = static_cast<QSerialPort::Parity>(
                ui->comboBox_parity_bit->itemData((ui->comboBox_parity_bit->currentIndex(),0)).toInt());
    m_currentSettings.stringParity = ui->comboBox_parity_bit->itemData(ui->comboBox_parity_bit->currentIndex(), 0).toString();

    m_currentSettings.stopBits = static_cast<QSerialPort::StopBits>(
                ui->comboBox_stop_bit->itemData((ui->comboBox_stop_bit->currentIndex(),0)).toInt());
    m_currentSettings.stringStopBits =  ui->comboBox_stop_bit->itemData(ui->comboBox_stop_bit->currentIndex(), 0).toString();

    m_currentSettings.flowControl = static_cast<QSerialPort::FlowControl>(
                ui->comboBox_flow_control->itemData((ui->comboBox_flow_control->currentIndex(),0)).toInt());
    m_currentSettings.stringFlowControl = ui->comboBox_flow_control->itemData(ui->comboBox_flow_control->currentIndex(), 0).toString();
}

void MainWindow::fillPortsInfo()
{
    //ui->comboBox_port_name->clear();

    QString description;
    QString manufacturer;
    QString serialNumber;
    QList<QString> port_name_list;
    const auto infos = QSerialPortInfo::availablePorts();
    for(const QSerialPortInfo &info : infos)
    {
        QStringList list;
        description = info.description();
        manufacturer = info.manufacturer();
        serialNumber = info.serialNumber();
        list << info.portName()
             << (!description.isEmpty() ? description : "")
             << (!manufacturer.isEmpty() ? manufacturer : "")
             << (!serialNumber.isEmpty() ? serialNumber : "")
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : "")
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : "");

        port_name_list.append(info.systemLocation());
    }
    int row;
    QString currentSelection;
    currentSelection = ui->comboBox_port_name->currentText();

    ui->comboBox_port_name->clear();
    for(int i = 0; i < port_name_list.count(); i++)
    {
        row = ui->comboBox_port_name->findText(port_name_list.at(i));
        if(row < 0)
        {
            ui->comboBox_port_name->addItem(port_name_list.at(i));
        }
    }

    row = ui->comboBox_port_name->findText(currentSelection);
    if(row >= 0)
    {
        ui->comboBox_port_name->setCurrentIndex(row);
    }


}

void MainWindow::availableSerialUpdate()
{
    while(1)
    {
        fillPortsInfo();
        QThread::sleep(1);
    }
}


void MainWindow::on_pushButton_connect_clicked()
{
    openSerialPort();
}

void MainWindow::on_pushButton_disconnect_clicked()
{
    closeSerialPort();
}
void MainWindow::openSerialPort()
{
    closeSerialPort();
    updateSettings();
    this->m_serial->setPortName(this->m_currentSettings.name);
    this->m_serial->setBaudRate(this->m_currentSettings.baudRate);
    this->m_serial->setDataBits(this->m_currentSettings.dataBits);
    this->m_serial->setParity(this->m_currentSettings.parity);
    this->m_serial->setStopBits(this->m_currentSettings.stopBits);
    this->m_serial->setFlowControl(this->m_currentSettings.flowControl);

    //    qDebug() << "port name: " << this->m_currentSettings.name;
    //    qDebug() << "baud rate: " << this->m_currentSettings.baudRate;
    //    qDebug() << "data bits: " << this->m_currentSettings.dataBits;
    //    qDebug() << "parity: " <<  this->m_currentSettings.parity;
    //    qDebug() << "stop bits: " << this->m_currentSettings.stopBits;
    //    qDebug() << "flow control: " << this->m_currentSettings.flowControl;

    if(!m_serial->open(QIODevice::ReadWrite))
    {
        QMessageBox::critical(this, tr("Error"), m_serial->errorString());
        //  qDebug() << "Could not open serial port...";

    }
    else
    {
        m_serial->flush();
        //  qDebug() << "Opened Serial port!";
    }
}

void MainWindow::closeSerialPort()
{

    if(m_serial->isOpen())
    {
        m_serial->close();
        ui->label_connection_status_value->setText("Disconnected");
        // qDebug() << "closeSerialPort(): Closed opened connection...";
    }
    else
    {
        //  qDebug() << "closeSerialPort(): No connection to close...";
    }
}
void MainWindow::readData()
{

    //    qDebug()<<"######"<<endl;
    const QByteArray data = m_serial->readAll();
    double nb = data.toDouble();
    //  qDebug()<<"nb:  "<<nb<<endl;

    sampling_thread->votages1 = nb;
    sampling_thread->waveformfunc1();


    //  ui->plainTextEdit_console->insertPlainText((QString::fromLocal8Bit(data.data()))+"\n");

}

void MainWindow::connectionStatusUpdate()
{
    while(1)
    {
        if(m_serial->isOpen() && m_serial->isReadable())
        {
            ui->label_connection_status_value->setText(m_serial->portName() + " Connected");
            //  qDebug() << "Serial port open!";
        }
        else
        {
            ui->label_connection_status_value->setText(m_serial->portName() + " Not Connected");
            // qDebug() << "Serial port appears to not have opened.";
        }

    }
}
