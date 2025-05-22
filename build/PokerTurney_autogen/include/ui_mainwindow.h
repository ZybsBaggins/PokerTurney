/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *tournamentList;
    QListWidget *playerList;
    QHBoxLayout *buttonLayout;
    QPushButton *createTournamentButton;
    QPushButton *addPlayerButton;
    QPushButton *assignPlayersButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        tournamentList = new QListWidget(centralwidget);
        tournamentList->setObjectName("tournamentList");
        tournamentList->setMinimumWidth(200);

        horizontalLayout->addWidget(tournamentList);

        playerList = new QListWidget(centralwidget);
        playerList->setObjectName("playerList");

        horizontalLayout->addWidget(playerList);


        verticalLayout->addLayout(horizontalLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        createTournamentButton = new QPushButton(centralwidget);
        createTournamentButton->setObjectName("createTournamentButton");

        buttonLayout->addWidget(createTournamentButton);

        addPlayerButton = new QPushButton(centralwidget);
        addPlayerButton->setObjectName("addPlayerButton");

        buttonLayout->addWidget(addPlayerButton);

        assignPlayersButton = new QPushButton(centralwidget);
        assignPlayersButton->setObjectName("assignPlayersButton");

        buttonLayout->addWidget(assignPlayersButton);


        verticalLayout->addLayout(buttonLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "PokerTurney", nullptr));
        createTournamentButton->setText(QCoreApplication::translate("MainWindow", "Create Tournament", nullptr));
        addPlayerButton->setText(QCoreApplication::translate("MainWindow", "Add Player", nullptr));
        assignPlayersButton->setText(QCoreApplication::translate("MainWindow", "Assign Players", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
