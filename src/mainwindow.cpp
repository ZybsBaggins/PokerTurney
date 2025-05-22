#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include "createtournamentdialog.h"
#include "addplayerdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load saved tournaments
    db.loadFromFile("tournaments.csv");

    loadTournaments();

    connect(ui->tournamentList, &QListWidget::itemClicked,
            this, &MainWindow::onTournamentSelected);

    connect(ui->addPlayerButton, &QPushButton::clicked,
            this, &MainWindow::onAddPlayerClicked);

    connect(ui->createTournamentButton, &QPushButton::clicked,
            this, &MainWindow::onCreateTournamentClicked);
}

MainWindow::~MainWindow() {
    db.saveToFile("tournaments.csv");
    delete ui;
}

void MainWindow::loadTournaments() {
    ui->tournamentList->clear();
    for (const auto& t : db.getTournaments()) {
        ui->tournamentList->addItem(QString::fromStdString(t.getName()));
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
        QString line = QString::fromStdString(tp.player->getName()) +
                       " | Placement: " +
                       (tp.placement == -1 ? "?" : QString::number(tp.placement)) +
                       " | On time: " +
                       (tp.onTime ? "Yes" : "No");
        ui->playerList->addItem(line);
    }
}


void MainWindow::onCreateTournamentClicked() {
    CreateTournamentDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        db.createTournament(
            dialog.getName().toStdString(),
            dialog.getType().toStdString(),
            dialog.getDate().toStdString(),
            dialog.getBuyIn(),
            dialog.getPrizePool(),
            dialog.getFactor()
            );
        loadTournaments();
    }
}

void MainWindow::onAddPlayerClicked() {
    AddPlayerDialog dialog(this);

    QStringList tournaments;
    for (const auto& t : db.getTournaments()) {
        tournaments << QString::fromStdString(t.getName());
    }
    dialog.setTournaments(tournaments);

    if (dialog.exec() == QDialog::Accepted) {
        std::string playerName = dialog.getPlayerName().toStdString();
        std::string tournamentName = dialog.getTournamentName().toStdString();

        db.addPlayer(playerName);
        db.assignPlayerToTournament(tournamentName, playerName);

        loadTournaments();
    }
}
