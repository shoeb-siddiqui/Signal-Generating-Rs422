/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
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
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QMenu *menuSINEWAVE;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
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
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
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

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionSINEWAVE->setText(QApplication::translate("MainWindow", "SINEWAVE", Q_NULLPTR));
        actionstart->setText(QApplication::translate("MainWindow", "start", Q_NULLPTR));
        actionstop->setText(QApplication::translate("MainWindow", "stop", Q_NULLPTR));
        actionSTEPAUTO->setText(QApplication::translate("MainWindow", "STEPAUTO", Q_NULLPTR));
        actionSTEPMANUAL->setText(QApplication::translate("MainWindow", "STEPMANUAL", Q_NULLPTR));
        actionRAMP->setText(QApplication::translate("MainWindow", "RAMP", Q_NULLPTR));
        actionTRIANGLE->setText(QApplication::translate("MainWindow", "TRIANGLE", Q_NULLPTR));
        actionSAWTOOTH->setText(QApplication::translate("MainWindow", "SAWTOOTH", Q_NULLPTR));
        actionSQUARE->setText(QApplication::translate("MainWindow", "SQUARE", Q_NULLPTR));
        actionSTALLFORCETEST->setText(QApplication::translate("MainWindow", "STALLFORCETEST", Q_NULLPTR));
        actionpSTEPAUTO->setText(QApplication::translate("MainWindow", "pSTEPAUTO", Q_NULLPTR));
        actionnSTEPAUTO->setText(QApplication::translate("MainWindow", "nSTEPAUTO", Q_NULLPTR));
        menuSINEWAVE->setTitle(QApplication::translate("MainWindow", "MENU", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
