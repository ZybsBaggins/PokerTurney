#include "playertournamenthistorydialog.h"
#include "ui_playertournamenthistorydialog.h"

PlayerTournamentHistoryDialog::PlayerTournamentHistoryDialog(Player* player, const std::vector<Tournament>& tournaments, QWidget *parent)
    : QDialog(parent), ui(new Ui::PlayerTournamentHistoryDialog) {
    ui->setupUi(this);

    setWindowTitle("Tournament History for " + player->getName());

    for (const auto& t : tournaments) {
        for (const auto& tp : t.getParticipants()) {
            if (tp.player == player) {
                QString line = t.getName() + " - Placement: " +
                    (tp.placement == -1 ? "?" : QString::number(tp.placement)) +
                    " - On time: " + (tp.onTime ? "Yes" : "No");

                int total = t.getParticipants().size();
                double ratio = (tp.placement != -1) ? static_cast<double>(total - tp.placement + 1) / total : 0.0;
                int points = static_cast<int>(ratio * t.getPrizePool());
                if (tp.onTime) points += 10;

                line += " - Points: " + QString::number(points);
                ui->listWidget->addItem(line);
            }
        }
    }
}

PlayerTournamentHistoryDialog::~PlayerTournamentHistoryDialog() {
    delete ui;
}
