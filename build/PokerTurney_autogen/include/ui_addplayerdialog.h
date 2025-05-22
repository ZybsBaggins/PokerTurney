/********************************************************************************
** Form generated from reading UI file 'addplayerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPLAYERDIALOG_H
#define UI_ADDPLAYERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddPlayerDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *playerNameEdit;
    QLabel *chipsLabel;
    QSpinBox *chipsSpin;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddPlayerDialog)
    {
        if (AddPlayerDialog->objectName().isEmpty())
            AddPlayerDialog->setObjectName("AddPlayerDialog");
        verticalLayout = new QVBoxLayout(AddPlayerDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        nameLabel = new QLabel(AddPlayerDialog);
        nameLabel->setObjectName("nameLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        playerNameEdit = new QLineEdit(AddPlayerDialog);
        playerNameEdit->setObjectName("playerNameEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, playerNameEdit);

        chipsLabel = new QLabel(AddPlayerDialog);
        chipsLabel->setObjectName("chipsLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, chipsLabel);

        chipsSpin = new QSpinBox(AddPlayerDialog);
        chipsSpin->setObjectName("chipsSpin");
        chipsSpin->setMinimum(0);
        chipsSpin->setMaximum(100000);
        chipsSpin->setValue(0);

        formLayout->setWidget(1, QFormLayout::FieldRole, chipsSpin);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(AddPlayerDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AddPlayerDialog);

        QMetaObject::connectSlotsByName(AddPlayerDialog);
    } // setupUi

    void retranslateUi(QDialog *AddPlayerDialog)
    {
        AddPlayerDialog->setWindowTitle(QCoreApplication::translate("AddPlayerDialog", "Add Player", nullptr));
        nameLabel->setText(QCoreApplication::translate("AddPlayerDialog", "Player Name:", nullptr));
        chipsLabel->setText(QCoreApplication::translate("AddPlayerDialog", "Chips:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPlayerDialog: public Ui_AddPlayerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPLAYERDIALOG_H
