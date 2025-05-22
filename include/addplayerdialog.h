#ifndef ADDPLAYERDIALOG_H
#define ADDPLAYERDIALOG_H

#include <QDialog>

namespace Ui {
class AddPlayerDialog;
}

class AddPlayerDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddPlayerDialog(QWidget *parent = nullptr);
    ~AddPlayerDialog();

    QString getPlayerName() const;
    QString getTournamentName() const;

    void setTournaments(const QStringList& tournaments);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddPlayerDialog *ui;
};

#endif // ADDPLAYERDIALOG_H
