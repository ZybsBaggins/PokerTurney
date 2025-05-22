#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include "createtournamentdialog.h"
#include "addplayerdialog.h"
#include "assignplayersdialog.h"
#include "playerresultdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load saved tournaments
    db.loadFromFile("tournaments.csv");
    db.loadPlayersFromFile("players.csv");

    loadPlayers();

    loadTournaments();

    connect(ui->tournamentList, &QListWidget::itemClicked,
            this, &MainWindow::onTournamentSelected);

    connect(ui->addPlayerButton, &QPushButton::clicked,
            this, &MainWindow::onAddPlayerClicked);

    connect(ui->createTournamentButton, &QPushButton::clicked,
            this, &MainWindow::onCreateTournamentClicked);

    connect(ui->assignPlayersButton, &QPushButton::clicked,
            this, &MainWindow::onAssignPlayersClicked);

    connect(ui->playerList, &QListWidget::itemDoubleClicked,
            this, &MainWindow::onPlayerDoubleClicked);
}

MainWindow::~MainWindow() {
    db.saveToFile("tournaments.csv");
    db.savePlayersToFile("players.csv");
    delete ui;
}

void MainWindow::loadTournaments() {
    ui->tournamentList->clear();
    for (const auto& t : db.getTournaments()) {
        ui->tournamentList->addItem(t.getName());
    }
}

void MainWindow::onTournamentSelected() {
    QListWidgetItem* item = ui->tournamentList->currentItem();
    if (!item) return;

    std::string name = item->text().toStdString();
    Tournament* t = db.findTournament(name);
    if (!t) return;

    ui->playerList->clear();
    for (const auto& tp : t->getParticipants()) {
        QString line = tp.player->getName() + " - "
            + (tp.placement == -1 ? "?" : QString::number(tp.placement)) + " - "
            + (tp.onTime ? "Yes" : "No");
        ui->playerList->addItem(line);
    }
}


void MainWindow::onCreateTournamentClicked() {
    CreateTournamentDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        db.createTournament(
            dialog.getName().toStdString(),
            dialog.getType().toStdString(),
            dialog.getDate().toString("yyyy-MM-dd").toStdString(),
            dialog.getBuyIn(),
            dialog.getPrizePool(),
            dialog.getFactor()
        );
        db.saveToFile("tournaments.csv"); // Save immediately after creation
        loadTournaments();
    }
}

void MainWindow::loadPlayers() {
    if (!ui->playerList) return;

    ui->playerList->clear();
    for (const auto& p : db.getPlayers()) {
        QString line = p.getName() +
                       " - Chips: " + QString::number(p.getChips()) +
                       " - Points: " + QString::number(p.getTotalPoints());
        ui->playerList->addItem(line);
    }
}

void MainWindow::onAddPlayerClicked() {
    AddPlayerDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        std::string playerName = dialog.getPlayerName().toStdString();
        int chips = dialog.getChips();

        db.addPlayer(playerName, chips);
        db.savePlayersToFile("players.csv"); // Gem straks
        loadPlayers(); // eller loadPlayers() hvis du viser listen separat
    }
}


void MainWindow::onAssignPlayersClicked() {
    QListWidgetItem* item = ui->tournamentList->currentItem();
    if (!item) {
        QMessageBox::warning(this, "No Tournament", "Please select a tournament first.");
        return;
    }

    std::string name = item->text().toStdString();
    Tournament* t = db.findTournament(name);
    if (!t) return;

    // Lav liste med pointere til spillere
    QVector<Player*> allPlayers;
    for (auto& p : db.getPlayers()) {
        allPlayers.append(&p);
    }

    AssignPlayersDialog dialog(t, allPlayers, this);
    if (dialog.exec() == QDialog::Accepted) {
        db.saveToFile("tournaments.csv");
        onTournamentSelected(); // opdater visningen af spillerne i turneringen
    }
}

void MainWindow::onPlayerDoubleClicked(QListWidgetItem* item) {
    auto* tItem = ui->tournamentList->currentItem();
    if (!tItem || !item) return;

    Tournament* t = db.findTournament(tItem->text().toStdString());
    if (!t) return;

    QString playerName = item->text().split(" - ").first();
    Player* p = db.findPlayer(playerName.toStdString());
    if (!p) return;

    // Hent turneringens deltagere
    auto participants = t->getParticipants();
    for (const auto& tp : participants) {
        if (tp.player == p) {
            PlayerResultDialog dialog(this);
            dialog.setPlacement(tp.placement == -1 ? 1 : tp.placement);
            dialog.setOnTime(tp.onTime);

            if (dialog.exec() == QDialog::Accepted) {
                t->updatePlacement(p, dialog.getPlacement());
                t->updateOnTime(p, dialog.getOnTime());

                db.saveToFile("tournaments.csv");
                onTournamentSelected();
            }
            break;
        }
    }
}


