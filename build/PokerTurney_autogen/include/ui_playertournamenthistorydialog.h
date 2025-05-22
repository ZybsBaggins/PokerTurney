/********************************************************************************
** Form generated from reading UI file 'playertournamenthistorydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERTOURNAMENTHISTORYDIALOG_H
#define UI_PLAYERTOURNAMENTHISTORYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PlayerTournamentHistoryDialog
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PlayerTournamentHistoryDialog)
    {
        if (PlayerTournamentHistoryDialog->objectName().isEmpty())
            PlayerTournamentHistoryDialog->setObjectName("PlayerTournamentHistoryDialog");
        verticalLayout = new QVBoxLayout(PlayerTournamentHistoryDialog);
        verticalLayout->setObjectName("verticalLayout");
        listWidget = new QListWidget(PlayerTournamentHistoryDialog);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        buttonBox = new QDialogButtonBox(PlayerTournamentHistoryDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(PlayerTournamentHistoryDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, PlayerTournamentHistoryDialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(PlayerTournamentHistoryDialog);
    } // setupUi

    void retranslateUi(QDialog *PlayerTournamentHistoryDialog)
    {
        PlayerTournamentHistoryDialog->setWindowTitle(QCoreApplication::translate("PlayerTournamentHistoryDialog", "Player Tournament History", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerTournamentHistoryDialog: public Ui_PlayerTournamentHistoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERTOURNAMENTHISTORYDIALOG_H
