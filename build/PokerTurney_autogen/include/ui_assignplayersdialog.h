/********************************************************************************
** Form generated from reading UI file 'assignplayersdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGNPLAYERSDIALOG_H
#define UI_ASSIGNPLAYERSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AssignPlayersDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *searchLineEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayoutPlayers;
    QPushButton *selectAllButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AssignPlayersDialog)
    {
        if (AssignPlayersDialog->objectName().isEmpty())
            AssignPlayersDialog->setObjectName("AssignPlayersDialog");
        AssignPlayersDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(AssignPlayersDialog);
        verticalLayout->setObjectName("verticalLayout");
        searchLineEdit = new QLineEdit(AssignPlayersDialog);
        searchLineEdit->setObjectName("searchLineEdit");

        verticalLayout->addWidget(searchLineEdit);

        scrollArea = new QScrollArea(AssignPlayersDialog);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 200));
        verticalLayoutPlayers = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayoutPlayers->setObjectName("verticalLayoutPlayers");
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        selectAllButton = new QPushButton(AssignPlayersDialog);
        selectAllButton->setObjectName("selectAllButton");

        verticalLayout->addWidget(selectAllButton);

        buttonBox = new QDialogButtonBox(AssignPlayersDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AssignPlayersDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AssignPlayersDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AssignPlayersDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AssignPlayersDialog);
    } // setupUi

    void retranslateUi(QDialog *AssignPlayersDialog)
    {
        AssignPlayersDialog->setWindowTitle(QCoreApplication::translate("AssignPlayersDialog", "Tilknyt spillere til turnering", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("AssignPlayersDialog", "S\303\270g efter spiller...", nullptr));
        selectAllButton->setText(QCoreApplication::translate("AssignPlayersDialog", "Tilknyt alle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AssignPlayersDialog: public Ui_AssignPlayersDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNPLAYERSDIALOG_H
