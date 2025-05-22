#include "createtournamentdialog.h"
#include "ui_createtournamentdialog.h"

CreateTournamentDialog::CreateTournamentDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::CreateTournamentDialog) {
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

CreateTournamentDialog::~CreateTournamentDialog() {
    delete ui;
}

QString CreateTournamentDialog::getName() const {
    return ui->nameEdit->text();
}

QString CreateTournamentDialog::getType() const {
    return ui->typeCombo->currentText();
}

QDate CreateTournamentDialog::getDate() const {
    return ui->dateEdit->date();
}

double CreateTournamentDialog::getBuyIn() const {
    return ui->buyInSpin->value();
}

double CreateTournamentDialog::getPrizePool() const {
    return ui->prizePoolSpin->value();
}

double CreateTournamentDialog::getFactor() const {
    return ui->factorSpin->value();
}
