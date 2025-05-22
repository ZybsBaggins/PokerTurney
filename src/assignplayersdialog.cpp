#include "assignplayersdialog.h"
#include "ui_assignplayersdialog.h"
#include <QCheckBox>
#include <QVBoxLayout>
#include <QDebug>

AssignPlayersDialog::AssignPlayersDialog(Tournament* tournament, const QVector<Player*>& allPlayers, QWidget *parent)
    : QDialog(parent), ui(new Ui::AssignPlayersDialog), tournament(tournament), allPlayers(allPlayers) {
    ui->setupUi(this);

    QVBoxLayout* layout = ui->verticalLayoutPlayers;

    for (Player* player : allPlayers) {
        QCheckBox* checkBox = new QCheckBox(player->getName(), this);
        checkBox->setProperty("player", QVariant::fromValue<void*>(player));
        layout->addWidget(checkBox);
    }

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &AssignPlayersDialog::on_buttonBox_accepted);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &AssignPlayersDialog::reject);
}

AssignPlayersDialog::~AssignPlayersDialog() {
    delete ui;
}

void AssignPlayersDialog::on_buttonBox_accepted() {
    QList<QCheckBox*> boxes = ui->scrollAreaWidgetContents->findChildren<QCheckBox*>();
    for (QCheckBox* box : boxes) {
        if (box->isChecked()) {
            Player* player = static_cast<Player*>(box->property("player").value<void*>());
            tournament->addPlayer(player);
        }
    }
    accept();
}
