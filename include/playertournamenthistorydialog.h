#ifndef PLAYERTOURNAMENTHISTORYDIALOG_H
#define PLAYERTOURNAMENTHISTORYDIALOG_H

#include <QDialog>
#include <QVector>
#include <QString>
#include "player.h"
#include "tournament.h"

namespace Ui {
class PlayerTournamentHistoryDialog;
}

class PlayerTournamentHistoryDialog : public QDialog {
    Q_OBJECT

public:
    explicit PlayerTournamentHistoryDialog(Player* player, const std::vector<Tournament>& tournaments, QWidget *parent = nullptr);
    ~PlayerTournamentHistoryDialog();

private:
    Ui::PlayerTournamentHistoryDialog *ui;
};

#endif // PLAYERTOURNAMENTHISTORYDIALOG_H
