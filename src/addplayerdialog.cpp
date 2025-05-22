#include "addplayerdialog.h"
#include "ui_addplayerdialog.h"

AddPlayerDialog::AddPlayerDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AddPlayerDialog) {
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

AddPlayerDialog::~AddPlayerDialog() {
    delete ui;
}

QString AddPlayerDialog::getPlayerName() const {
    return ui->playerNameEdit->text();
}

QString AddPlayerDialog::getTournamentName() const {
    return ui->tournamentCombo->currentText();
}

void AddPlayerDialog::setTournaments(const QStringList& tournaments) {
    ui->tournamentCombo->clear();
    ui->tournamentCombo->addItems(tournaments);
}

void AddPlayerDialog::on_buttonBox_accepted()
{

}

