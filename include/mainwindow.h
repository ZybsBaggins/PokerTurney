#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    Database db;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onTournamentSelected();
    void onAddPlayerClicked();
    void onCreateTournamentClicked();

private:
    Ui::MainWindow *ui;

    void loadTournaments();
    void updateTournamentView();
};
#endif // MAINWINDOW_H
