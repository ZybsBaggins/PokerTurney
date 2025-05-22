#ifndef ASSIGNPLAYERSDIALOG_H
#define ASSIGNPLAYERSDIALOG_H

#include <QDialog>
#include <QVector>
#include "player.h"
#include "tournament.h"

namespace Ui {
class AssignPlayersDialog;
}

class AssignPlayersDialog : public QDialog {
    Q_OBJECT

public:
    explicit AssignPlayersDialog(Tournament* tournament, const QVector<Player*>& allPlayers, QWidget *parent = nullptr);
    ~AssignPlayersDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AssignPlayersDialog *ui;
    Tournament* tournament;
    QVector<Player*> allPlayers;
};

#endif // ASSIGNPLAYERSDIALOG_H