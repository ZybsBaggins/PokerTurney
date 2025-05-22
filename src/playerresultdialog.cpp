#include "playerresultdialog.h"
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QSpinBox>
#include <QCheckBox>

PlayerResultDialog::PlayerResultDialog(QWidget *parent)
    : QDialog(parent) {
    auto* layout = new QVBoxLayout(this);
    auto* form = new QFormLayout();

    placementSpin = new QSpinBox(this);
    placementSpin->setMinimum(1);
    placementSpin->setMaximum(100);

    onTimeCheck = new QCheckBox("Arrived on time", this);

    form->addRow("Placement:", placementSpin);
    form->addRow("", onTimeCheck);

    layout->addLayout(form);

    auto* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    layout->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

int PlayerResultDialog::getPlacement() const {
    return placementSpin->value();
}

bool PlayerResultDialog::getOnTime() const {
    return onTimeCheck->isChecked();
}

void PlayerResultDialog::setPlacement(int p) {
    placementSpin->setValue(p);
}

void PlayerResultDialog::setOnTime(bool on) {
    onTimeCheck->setChecked(on);
}
