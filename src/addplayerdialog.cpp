#include "addplayerdialog.h"
#include "ui_addplayerdialog.h"

AddPlayerDialog::AddPlayerDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AddPlayerDialog) {
    ui->setupUi(this);

    // Knyt OK og Cancel knapper til dialog kontrol
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

AddPlayerDialog::~AddPlayerDialog() {
    delete ui;
}

QString AddPlayerDialog::getPlayerName() const {
    return ui->playerNameEdit->text();
}

int AddPlayerDialog::getChips() const {
    return ui->chipsSpin->value();
}
