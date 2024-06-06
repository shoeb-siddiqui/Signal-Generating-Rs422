/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSINEWAVE;
    QAction *actionstart;
    QAction *actionstop;
    QAction *actionSTEPAUTO;
    QAction *actionSTEPMANUAL;
    QAction *actionRAMP;
    QAction *actionTRIANGLE;
    QAction *actionSAWTOOTH;
    QAction *actionSQUARE;
    QAction *actionSTALLFORCETEST;
    QAction *actionpSTEPAUTO;
    QAction *actionnSTEPAUTO;
    QAction *actionclear;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_port_name;
    QComboBox *comboBox_port_name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_baud_rate;
    QComboBox *comboBox_baud_rate;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_data_bits;
    QComboBox *comboBox_data_bits;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_parity_bit;
    QComboBox *comboBox_parity_bit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_stop_bit;
    QComboBox *comboBox_stop_bit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_flow_control;
    QComboBox *comboBox_flow_control;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_connection_status;
    QLabel *label_connection_status_value;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_disconnect;
    QPushButton *pushButton_connect;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QMenu *menuSINEWAVE;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(869, 487);
        actionSINEWAVE = new QAction(MainWindow);
        actionSINEWAVE->setObjectName(QStringLiteral("actionSINEWAVE"));
        actionstart = new QAction(MainWindow);
        actionstart->setObjectName(QStringLiteral("actionstart"));
        actionstop = new QAction(MainWindow);
        actionstop->setObjectName(QStringLiteral("actionstop"));
        actionSTEPAUTO = new QAction(MainWindow);
        actionSTEPAUTO->setObjectName(QStringLiteral("actionSTEPAUTO"));
        actionSTEPMANUAL = new QAction(MainWindow);
        actionSTEPMANUAL->setObjectName(QStringLiteral("actionSTEPMANUAL"));
        actionRAMP = new QAction(MainWindow);
        actionRAMP->setObjectName(QStringLiteral("actionRAMP"));
        actionTRIANGLE = new QAction(MainWindow);
        actionTRIANGLE->setObjectName(QStringLiteral("actionTRIANGLE"));
        actionSAWTOOTH = new QAction(MainWindow);
        actionSAWTOOTH->setObjectName(QStringLiteral("actionSAWTOOTH"));
        actionSQUARE = new QAction(MainWindow);
        actionSQUARE->setObjectName(QStringLiteral("actionSQUARE"));
        actionSTALLFORCETEST = new QAction(MainWindow);
        actionSTALLFORCETEST->setObjectName(QStringLiteral("actionSTALLFORCETEST"));
        actionpSTEPAUTO = new QAction(MainWindow);
        actionpSTEPAUTO->setObjectName(QStringLiteral("actionpSTEPAUTO"));
        actionnSTEPAUTO = new QAction(MainWindow);
        actionnSTEPAUTO->setObjectName(QStringLiteral("actionnSTEPAUTO"));
        actionclear = new QAction(MainWindow);
        actionclear->setObjectName(QStringLiteral("actionclear"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_port_name = new QLabel(centralWidget);
        label_port_name->setObjectName(QStringLiteral("label_port_name"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_port_name->sizePolicy().hasHeightForWidth());
        label_port_name->setSizePolicy(sizePolicy);
        label_port_name->setMinimumSize(QSize(0, 0));
        label_port_name->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(label_port_name);

        comboBox_port_name = new QComboBox(centralWidget);
        comboBox_port_name->setObjectName(QStringLiteral("comboBox_port_name"));
        sizePolicy.setHeightForWidth(comboBox_port_name->sizePolicy().hasHeightForWidth());
        comboBox_port_name->setSizePolicy(sizePolicy);
        comboBox_port_name->setMinimumSize(QSize(0, 0));
        comboBox_port_name->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(comboBox_port_name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_baud_rate = new QLabel(centralWidget);
        label_baud_rate->setObjectName(QStringLiteral("label_baud_rate"));
        sizePolicy.setHeightForWidth(label_baud_rate->sizePolicy().hasHeightForWidth());
        label_baud_rate->setSizePolicy(sizePolicy);
        label_baud_rate->setMinimumSize(QSize(0, 0));
        label_baud_rate->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(label_baud_rate);

        comboBox_baud_rate = new QComboBox(centralWidget);
        comboBox_baud_rate->setObjectName(QStringLiteral("comboBox_baud_rate"));
        sizePolicy.setHeightForWidth(comboBox_baud_rate->sizePolicy().hasHeightForWidth());
        comboBox_baud_rate->setSizePolicy(sizePolicy);
        comboBox_baud_rate->setMinimumSize(QSize(0, 0));
        comboBox_baud_rate->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(comboBox_baud_rate);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_data_bits = new QLabel(centralWidget);
        label_data_bits->setObjectName(QStringLiteral("label_data_bits"));
        sizePolicy.setHeightForWidth(label_data_bits->sizePolicy().hasHeightForWidth());
        label_data_bits->setSizePolicy(sizePolicy);
        label_data_bits->setMinimumSize(QSize(0, 0));
        label_data_bits->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(label_data_bits);

        comboBox_data_bits = new QComboBox(centralWidget);
        comboBox_data_bits->setObjectName(QStringLiteral("comboBox_data_bits"));
        sizePolicy.setHeightForWidth(comboBox_data_bits->sizePolicy().hasHeightForWidth());
        comboBox_data_bits->setSizePolicy(sizePolicy);
        comboBox_data_bits->setMinimumSize(QSize(0, 0));
        comboBox_data_bits->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_3->addWidget(comboBox_data_bits);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_parity_bit = new QLabel(centralWidget);
        label_parity_bit->setObjectName(QStringLiteral("label_parity_bit"));
        sizePolicy.setHeightForWidth(label_parity_bit->sizePolicy().hasHeightForWidth());
        label_parity_bit->setSizePolicy(sizePolicy);
        label_parity_bit->setMinimumSize(QSize(0, 0));
        label_parity_bit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_4->addWidget(label_parity_bit);

        comboBox_parity_bit = new QComboBox(centralWidget);
        comboBox_parity_bit->setObjectName(QStringLiteral("comboBox_parity_bit"));
        sizePolicy.setHeightForWidth(comboBox_parity_bit->sizePolicy().hasHeightForWidth());
        comboBox_parity_bit->setSizePolicy(sizePolicy);
        comboBox_parity_bit->setMinimumSize(QSize(0, 0));
        comboBox_parity_bit->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(comboBox_parity_bit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_stop_bit = new QLabel(centralWidget);
        label_stop_bit->setObjectName(QStringLiteral("label_stop_bit"));
        sizePolicy.setHeightForWidth(label_stop_bit->sizePolicy().hasHeightForWidth());
        label_stop_bit->setSizePolicy(sizePolicy);
        label_stop_bit->setMinimumSize(QSize(0, 0));
        label_stop_bit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_5->addWidget(label_stop_bit);

        comboBox_stop_bit = new QComboBox(centralWidget);
        comboBox_stop_bit->setObjectName(QStringLiteral("comboBox_stop_bit"));
        sizePolicy.setHeightForWidth(comboBox_stop_bit->sizePolicy().hasHeightForWidth());
        comboBox_stop_bit->setSizePolicy(sizePolicy);
        comboBox_stop_bit->setMinimumSize(QSize(0, 0));
        comboBox_stop_bit->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(comboBox_stop_bit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_flow_control = new QLabel(centralWidget);
        label_flow_control->setObjectName(QStringLiteral("label_flow_control"));
        sizePolicy.setHeightForWidth(label_flow_control->sizePolicy().hasHeightForWidth());
        label_flow_control->setSizePolicy(sizePolicy);
        label_flow_control->setMinimumSize(QSize(0, 0));
        label_flow_control->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_6->addWidget(label_flow_control);

        comboBox_flow_control = new QComboBox(centralWidget);
        comboBox_flow_control->setObjectName(QStringLiteral("comboBox_flow_control"));
        sizePolicy.setHeightForWidth(comboBox_flow_control->sizePolicy().hasHeightForWidth());
        comboBox_flow_control->setSizePolicy(sizePolicy);
        comboBox_flow_control->setMinimumSize(QSize(0, 0));
        comboBox_flow_control->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_6->addWidget(comboBox_flow_control);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_connection_status = new QLabel(centralWidget);
        label_connection_status->setObjectName(QStringLiteral("label_connection_status"));
        sizePolicy.setHeightForWidth(label_connection_status->sizePolicy().hasHeightForWidth());
        label_connection_status->setSizePolicy(sizePolicy);
        label_connection_status->setMinimumSize(QSize(0, 0));
        label_connection_status->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_7->addWidget(label_connection_status);

        label_connection_status_value = new QLabel(centralWidget);
        label_connection_status_value->setObjectName(QStringLiteral("label_connection_status_value"));
        sizePolicy.setHeightForWidth(label_connection_status_value->sizePolicy().hasHeightForWidth());
        label_connection_status_value->setSizePolicy(sizePolicy);
        label_connection_status_value->setMinimumSize(QSize(125, 0));

        horizontalLayout_7->addWidget(label_connection_status_value);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        pushButton_disconnect = new QPushButton(centralWidget);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));
        sizePolicy.setHeightForWidth(pushButton_disconnect->sizePolicy().hasHeightForWidth());
        pushButton_disconnect->setSizePolicy(sizePolicy);
        pushButton_disconnect->setMinimumSize(QSize(0, 0));
        pushButton_disconnect->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_8->addWidget(pushButton_disconnect);

        pushButton_connect = new QPushButton(centralWidget);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        sizePolicy.setHeightForWidth(pushButton_connect->sizePolicy().hasHeightForWidth());
        pushButton_connect->setSizePolicy(sizePolicy);
        pushButton_connect->setMinimumSize(QSize(0, 0));
        pushButton_connect->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_8->addWidget(pushButton_connect);


        verticalLayout->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_9->addLayout(verticalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        horizontalLayout_9->addLayout(gridLayout);


        gridLayout_2->addLayout(horizontalLayout_9, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 869, 21));
        menuSINEWAVE = new QMenu(menuBar);
        menuSINEWAVE->setObjectName(QStringLiteral("menuSINEWAVE"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSINEWAVE->menuAction());
        menuSINEWAVE->addAction(actionSINEWAVE);
        menuSINEWAVE->addAction(actionSTEPAUTO);
        menuSINEWAVE->addAction(actionSTEPMANUAL);
        menuSINEWAVE->addAction(actionRAMP);
        menuSINEWAVE->addAction(actionTRIANGLE);
        menuSINEWAVE->addAction(actionSAWTOOTH);
        menuSINEWAVE->addAction(actionSQUARE);
        menuSINEWAVE->addAction(actionSTALLFORCETEST);
        menuSINEWAVE->addAction(actionpSTEPAUTO);
        menuSINEWAVE->addAction(actionnSTEPAUTO);
        menuSINEWAVE->addAction(actionstart);
        menuSINEWAVE->addAction(actionstop);
        menuSINEWAVE->addAction(actionclear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionSINEWAVE->setText(QApplication::translate("MainWindow", "SINEWAVE", 0));
        actionstart->setText(QApplication::translate("MainWindow", "start", 0));
        actionstop->setText(QApplication::translate("MainWindow", "stop", 0));
        actionSTEPAUTO->setText(QApplication::translate("MainWindow", "STEPAUTO", 0));
        actionSTEPMANUAL->setText(QApplication::translate("MainWindow", "STEPMANUAL", 0));
        actionRAMP->setText(QApplication::translate("MainWindow", "RAMP", 0));
        actionTRIANGLE->setText(QApplication::translate("MainWindow", "TRIANGLE", 0));
        actionSAWTOOTH->setText(QApplication::translate("MainWindow", "SAWTOOTH", 0));
        actionSQUARE->setText(QApplication::translate("MainWindow", "SQUARE", 0));
        actionSTALLFORCETEST->setText(QApplication::translate("MainWindow", "STALLFORCETEST", 0));
        actionpSTEPAUTO->setText(QApplication::translate("MainWindow", "pSTEPAUTO", 0));
        actionnSTEPAUTO->setText(QApplication::translate("MainWindow", "nSTEPAUTO", 0));
        actionclear->setText(QApplication::translate("MainWindow", "clear", 0));
        label_port_name->setText(QApplication::translate("MainWindow", "Port Name: ", 0));
        label_baud_rate->setText(QApplication::translate("MainWindow", "Baud Rate: ", 0));
        label_data_bits->setText(QApplication::translate("MainWindow", "Data Bits:", 0));
        label_parity_bit->setText(QApplication::translate("MainWindow", "Partity Bit:", 0));
        label_stop_bit->setText(QApplication::translate("MainWindow", "Stop Bit: ", 0));
        label_flow_control->setText(QApplication::translate("MainWindow", "Flow Control:", 0));
        label_connection_status->setText(QApplication::translate("MainWindow", "Connection Status: ", 0));
        label_connection_status_value->setText(QApplication::translate("MainWindow", "Disconnected", 0));
        pushButton_disconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0));
        pushButton_connect->setText(QApplication::translate("MainWindow", "Connect", 0));
        menuSINEWAVE->setTitle(QApplication::translate("MainWindow", "MENU", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
