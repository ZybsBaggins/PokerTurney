#ifndef CREATETOURNAMENTDIALOG_H
#define CREATETOURNAMENTDIALOG_H

#include <QDialog>

namespace Ui {
class CreateTournamentDialog;
}

class CreateTournamentDialog : public QDialog {
    Q_OBJECT

public:
    explicit CreateTournamentDialog(QWidget *parent = nullptr);
    ~CreateTournamentDialog();

    QString getName() const;
    QString getType() const;
    QDate getDate() const;
    double getBuyIn() const;
    double getPrizePool() const;
    double getFactor() const;

private:
    Ui::CreateTournamentDialog *ui;
};

#endif // CREATETOURNAMENTDIALOG_H