#include "assignplayersdialog.h"
#include "ui_assignplayersdialog.h"
#include <QCheckBox>
#include <QVBoxLayout>

AssignPlayersDialog::AssignPlayersDialog(Tournament* tournament, const QVector<Player*>& allPlayers, QWidget *parent)
    : QDialog(parent), ui(new Ui::AssignPlayersDialog), tournament(tournament), allPlayers(allPlayers) {
    ui->setupUi(this);

    QVBoxLayout* layout = new QVBoxLayout;
    for (Player* player : allPlayers) {
        QCheckBox* checkBox = new QCheckBox(player->getName(), this);
        checkBox->setProperty("player", QVariant::fromValue<void*>(player));
        layout->addWidget(checkBox);
    }
    ui->scrollAreaWidgetContents->setLayout(layout);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
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
}
