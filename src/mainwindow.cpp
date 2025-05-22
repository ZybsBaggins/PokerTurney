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
    for (const auto& tp : t->getPlayers()) {
        QString line = tp->getName() + " - " +
                       (tp->getPlacement() == -1 ? "?" : QString::number(tp->getPlacement())) + " - " +
                       (tp->getOnTime() ? "Yes" : "No");
        ui->playerList->addItem(line);
    }
}


void MainWindow::onCreateTournamentClicked() {
    CreateTournamentDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        db.createTournament(
            dialog.getName().toStdString(),
            dialog.getType().toStdString(),
            dialog.getDate().toString("yyyy-MM-dd").toStdString(), // ✅ FIX
            dialog.getBuyIn(),
            dialog.getPrizePool(),
            dialog.getFactor()
            );
        loadTournaments();
    }
}

void MainWindow::onAddPlayerClicked() {
    AddPlayerDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        std::string playerName = dialog.getPlayerName().toStdString();
        int chips = dialog.getChips();

        db.addPlayer(playerName, chips); // tilføj chips her hvis nødvendigt
        loadTournaments();
    }
}
