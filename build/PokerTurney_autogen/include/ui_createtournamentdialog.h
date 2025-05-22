/********************************************************************************
** Form generated from reading UI file 'createtournamentdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETOURNAMENTDIALOG_H
#define UI_CREATETOURNAMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateTournamentDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *typeLabel;
    QComboBox *typeCombo;
    QLabel *dateLabel;
    QDateEdit *dateEdit;
    QLabel *buyInLabel;
    QDoubleSpinBox *buyInSpin;
    QLabel *prizePoolLabel;
    QDoubleSpinBox *prizePoolSpin;
    QLabel *factorLabel;
    QDoubleSpinBox *factorSpin;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CreateTournamentDialog)
    {
        if (CreateTournamentDialog->objectName().isEmpty())
            CreateTournamentDialog->setObjectName("CreateTournamentDialog");
        CreateTournamentDialog->resize(239, 300);
        verticalLayout = new QVBoxLayout(CreateTournamentDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        nameLabel = new QLabel(CreateTournamentDialog);
        nameLabel->setObjectName("nameLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameEdit = new QLineEdit(CreateTournamentDialog);
        nameEdit->setObjectName("nameEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        typeLabel = new QLabel(CreateTournamentDialog);
        typeLabel->setObjectName("typeLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, typeLabel);

        typeCombo = new QComboBox(CreateTournamentDialog);
        typeCombo->addItem(QString());
        typeCombo->addItem(QString());
        typeCombo->addItem(QString());
        typeCombo->setObjectName("typeCombo");

        formLayout->setWidget(1, QFormLayout::FieldRole, typeCombo);

        dateLabel = new QLabel(CreateTournamentDialog);
        dateLabel->setObjectName("dateLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, dateLabel);

        dateEdit = new QDateEdit(CreateTournamentDialog);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setCalendarPopup(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, dateEdit);

        buyInLabel = new QLabel(CreateTournamentDialog);
        buyInLabel->setObjectName("buyInLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, buyInLabel);

        buyInSpin = new QDoubleSpinBox(CreateTournamentDialog);
        buyInSpin->setObjectName("buyInSpin");
        buyInSpin->setDecimals(2);
        buyInSpin->setMaximum(100000.000000000000000);

        formLayout->setWidget(3, QFormLayout::FieldRole, buyInSpin);

        prizePoolLabel = new QLabel(CreateTournamentDialog);
        prizePoolLabel->setObjectName("prizePoolLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, prizePoolLabel);

        prizePoolSpin = new QDoubleSpinBox(CreateTournamentDialog);
        prizePoolSpin->setObjectName("prizePoolSpin");
        prizePoolSpin->setDecimals(2);
        prizePoolSpin->setMaximum(1000000.000000000000000);

        formLayout->setWidget(4, QFormLayout::FieldRole, prizePoolSpin);

        factorLabel = new QLabel(CreateTournamentDialog);
        factorLabel->setObjectName("factorLabel");

        formLayout->setWidget(5, QFormLayout::LabelRole, factorLabel);

        factorSpin = new QDoubleSpinBox(CreateTournamentDialog);
        factorSpin->setObjectName("factorSpin");
        factorSpin->setDecimals(2);
        factorSpin->setMaximum(10.000000000000000);
        factorSpin->setSingleStep(0.100000000000000);
        factorSpin->setValue(1.000000000000000);

        formLayout->setWidget(5, QFormLayout::FieldRole, factorSpin);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(CreateTournamentDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CreateTournamentDialog);

        QMetaObject::connectSlotsByName(CreateTournamentDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateTournamentDialog)
    {
        CreateTournamentDialog->setWindowTitle(QCoreApplication::translate("CreateTournamentDialog", "Create Tournament", nullptr));
        nameLabel->setText(QCoreApplication::translate("CreateTournamentDialog", "Name:", nullptr));
        typeLabel->setText(QCoreApplication::translate("CreateTournamentDialog", "Type:", nullptr));
        typeCombo->setItemText(0, QCoreApplication::translate("CreateTournamentDialog", "Cash", nullptr));
        typeCombo->setItemText(1, QCoreApplication::translate("CreateTournamentDialog", "Omaha", nullptr));
        typeCombo->setItemText(2, QCoreApplication::translate("CreateTournamentDialog", "Online", nullptr));

        dateLabel->setText(QCoreApplication::translate("CreateTournamentDialog", "Date:", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("CreateTournamentDialog", "yyyy-MM-dd", nullptr));
        buyInLabel->setText(QCoreApplication::translate("CreateTournamentDialog", "Buy-in:", nullptr));
        prizePoolLabel->setText(QCoreApplication::translate("CreateTournamentDialog", "Prize Pool:", nullptr));
        factorLabel->setText(QCoreApplication::translate("CreateTournamentDialog", "Factor:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateTournamentDialog: public Ui_CreateTournamentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETOURNAMENTDIALOG_H
