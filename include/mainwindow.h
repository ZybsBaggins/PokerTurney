#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
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
    void onAssignPlayersClicked();
    void onPlayerDoubleClicked(QListWidgetItem* item);
    void onTotalPointsDoubleClicked(QListWidgetItem* item);
    void filterTournaments(const QString& text);
    void filterPlayers(const QString& text);
    void filterTotalPoints(const QString& text);

    void updateTotalPointsList();
    void onRemovePlayerFromTournamentClicked();


private:
    Ui::MainWindow *ui;

    void loadTournaments();
    void loadPlayers();  // ✅ tilføjet
    void updateTournamentView();
};

#endif // MAINWINDOW_H
