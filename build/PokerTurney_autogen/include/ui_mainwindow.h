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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QVBoxLayout *vboxLayout;
    QLabel *tournamentLabel;
    QLineEdit *tournamentSearch;
    QListWidget *tournamentList;
    QVBoxLayout *vboxLayout1;
    QLabel *playerLabel;
    QLineEdit *playerSearch;
    QListWidget *playerList;
    QVBoxLayout *vboxLayout2;
    QLabel *totalPointsLabel;
    QLineEdit *totalPointSearch;
    QListWidget *totalPointsList;
    QHBoxLayout *buttonLayout;
    QPushButton *createTournamentButton;
    QPushButton *addPlayerButton;
    QPushButton *assignPlayersButton;
    QPushButton *removePlayerFromTournamentButton;
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
        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName("vboxLayout");
        tournamentLabel = new QLabel(centralwidget);
        tournamentLabel->setObjectName("tournamentLabel");
        tournamentLabel->setAlignment(Qt::AlignCenter);

        vboxLayout->addWidget(tournamentLabel);

        tournamentSearch = new QLineEdit(centralwidget);
        tournamentSearch->setObjectName("tournamentSearch");

        vboxLayout->addWidget(tournamentSearch);

        tournamentList = new QListWidget(centralwidget);
        tournamentList->setObjectName("tournamentList");
        tournamentList->setMinimumWidth(200);

        vboxLayout->addWidget(tournamentList);


        horizontalLayout->addLayout(vboxLayout);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName("vboxLayout1");
        playerLabel = new QLabel(centralwidget);
        playerLabel->setObjectName("playerLabel");
        playerLabel->setAlignment(Qt::AlignCenter);

        vboxLayout1->addWidget(playerLabel);

        playerSearch = new QLineEdit(centralwidget);
        playerSearch->setObjectName("playerSearch");

        vboxLayout1->addWidget(playerSearch);

        playerList = new QListWidget(centralwidget);
        playerList->setObjectName("playerList");

        vboxLayout1->addWidget(playerList);


        horizontalLayout->addLayout(vboxLayout1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setObjectName("vboxLayout2");
        totalPointsLabel = new QLabel(centralwidget);
        totalPointsLabel->setObjectName("totalPointsLabel");
        totalPointsLabel->setAlignment(Qt::AlignCenter);

        vboxLayout2->addWidget(totalPointsLabel);

        totalPointSearch = new QLineEdit(centralwidget);
        totalPointSearch->setObjectName("totalPointSearch");

        vboxLayout2->addWidget(totalPointSearch);

        totalPointsList = new QListWidget(centralwidget);
        totalPointsList->setObjectName("totalPointsList");

        vboxLayout2->addWidget(totalPointsList);


        horizontalLayout->addLayout(vboxLayout2);


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

        removePlayerFromTournamentButton = new QPushButton(centralwidget);
        removePlayerFromTournamentButton->setObjectName("removePlayerFromTournamentButton");

        buttonLayout->addWidget(removePlayerFromTournamentButton);


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
        tournamentLabel->setText(QCoreApplication::translate("MainWindow", "Turnering", nullptr));
        playerLabel->setText(QCoreApplication::translate("MainWindow", "Spillere", nullptr));
        totalPointsLabel->setText(QCoreApplication::translate("MainWindow", "Leaderboard", nullptr));
        createTournamentButton->setText(QCoreApplication::translate("MainWindow", "Create Tournament", nullptr));
        addPlayerButton->setText(QCoreApplication::translate("MainWindow", "Add Player", nullptr));
        assignPlayersButton->setText(QCoreApplication::translate("MainWindow", "Assign Players", nullptr));
        removePlayerFromTournamentButton->setText(QCoreApplication::translate("MainWindow", "Remove Player", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
