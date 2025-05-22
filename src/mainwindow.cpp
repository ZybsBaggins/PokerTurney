#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include "createtournamentdialog.h"
#include "addplayerdialog.h"
#include "assignplayersdialog.h"
#include "playerresultdialog.h"
#include "playertournamenthistorydialog.h"

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

    connect(ui->totalPointsList, &QListWidget::itemDoubleClicked,
            this, &MainWindow::onTotalPointsDoubleClicked);
            
    connect(ui->removePlayerFromTournamentButton, &QPushButton::clicked,
            this, &MainWindow::onRemovePlayerFromTournamentClicked);

    connect(ui->tournamentSearch, &QLineEdit::textChanged, this, &MainWindow::filterTournaments);
    connect(ui->playerSearch, &QLineEdit::textChanged, this, &MainWindow::filterPlayers);
    connect(ui->totalPointSearch, &QLineEdit::textChanged, this, &MainWindow::filterTotalPoints);
            
        

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

    db.calculateAllPoints();

    std::string name = item->text().toStdString();
    Tournament* t = db.findTournament(name);
    if (!t) return;

    ui->playerList->clear();

    int totalPlayers = t->getParticipants().size();
    double prizePool = t->getPrizePool(); // Præmiepulje skal være tilgængelig fra Tournament
    if (prizePool <= 0) prizePool = 1; // Beskyt mod 0 eller negative værdier

    for (const auto& tp : t->getParticipants()) {
        QString line = tp.player->getName() + " - " +
                       (tp.placement == -1 ? "?" : QString::number(tp.placement)) + " - " +
                       (tp.onTime ? "Yes" : "No");

        // Beregn point kun hvis placering er sat
        double placementPoints = 0;
        if (tp.placement != -1) {
            double sqrtPrize = std::sqrt(prizePool);
            placementPoints = ((double)(totalPlayers - tp.placement + 1) / totalPlayers) * sqrtPrize * 10;
        }

        // Bonuspoint
        int bonusPoints = 0;
        if (tp.onTime) bonusPoints += 10;

        int totalPoints = static_cast<int>(placementPoints + bonusPoints);

        line += " - Points: " + QString::number(totalPoints);
        ui->playerList->addItem(line);
    }

    updateTotalPointsList();
}


void MainWindow::onCreateTournamentClicked() {
    CreateTournamentDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        db.createTournament(
            dialog.getName().toStdString(),
            dialog.getType().toStdString(),
            dialog.getDate().toString("yyyy-MM-dd").toStdString(),
            dialog.getBuyIn(),
            dialog.getPrizePool()
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


void MainWindow::updateTotalPointsList() {
    ui->totalPointsList->clear();

    // Kopiér spillere ind i sortérbar liste
    std::vector<Player*> sortedPlayers;
    for (auto& p : db.getPlayers()) {
        sortedPlayers.push_back(&p);
    }

    // Sortér synkende efter point
    std::sort(sortedPlayers.begin(), sortedPlayers.end(),
              [](Player* a, Player* b) {
                  return a->getTotalPoints() > b->getTotalPoints();
              });

    // Tilføj til GUI
    for (const auto& p : sortedPlayers) {
        QString entry = p->getName() + " - Total Points: " + QString::number(p->getTotalPoints());
        ui->totalPointsList->addItem(entry);
    }
}

void MainWindow::onPlayerDoubleClicked(QListWidgetItem* item) {
    QString playerName = item->text().split(" - ").first();
    Player* p = db.findPlayer(playerName.toStdString());
    if (!p) return;

    QListWidgetItem* selectedTournament = ui->tournamentList->currentItem();

    if (selectedTournament) {
        Tournament* t = db.findTournament(selectedTournament->text().toStdString());
        if (!t) return;

        for (const auto& tp : t->getParticipants()) {
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
                return;
            }
        }
    }

    // Ingen turnering valgt → vis historik
    PlayerTournamentHistoryDialog dialog(p, db.getTournaments(), this);
    dialog.exec();
}

void MainWindow::onTotalPointsDoubleClicked(QListWidgetItem* item) {
    if (!item) return;

    QString playerName = item->text().split(" - ").first();
    Player* p = db.findPlayer(playerName.toStdString());
    if (!p) return;

    PlayerTournamentHistoryDialog dialog(p, db.getTournaments(), this);
    dialog.exec();
}

void MainWindow::onRemovePlayerFromTournamentClicked() {
    QListWidgetItem* tournamentItem = ui->tournamentList->currentItem();
    QListWidgetItem* playerItem = ui->playerList->currentItem();

    if (!tournamentItem || !playerItem) {
        QMessageBox::warning(this, "Selection Error", "Please select both a tournament and a player.");
        return;
    }

    QString tournamentName = tournamentItem->text();
    Tournament* t = db.findTournament(tournamentName.toStdString());
    if (!t) return;

    QString playerName = playerItem->text().split(" - ").first();
    Player* p = db.findPlayer(playerName.toStdString());
    if (!p) return;

    QVector<TournamentParticipant> updated;
    for (const auto& tp : t->getParticipants()) {
        if (tp.player != p)
            updated.append(tp);
    }

    t->setParticipants(updated);

    db.saveToFile("tournaments.csv");
    onTournamentSelected(); // Opdater visning
}


void MainWindow::filterTotalPoints(const QString& text) {
    updateTotalPointsList(); // reset
    for (int i = 0; i < ui->totalPointsList->count(); ++i) {
        QListWidgetItem* item = ui->totalPointsList->item(i);
        item->setHidden(!item->text().contains(text, Qt::CaseInsensitive));
    }
}

void MainWindow::filterPlayers(const QString& text) {
    loadPlayers(); // reset
    for (int i = 0; i < ui->playerList->count(); ++i) {
        QListWidgetItem* item = ui->playerList->item(i);
        item->setHidden(!item->text().contains(text, Qt::CaseInsensitive));
    }
}

void MainWindow::filterTournaments(const QString& text) {
    loadTournaments(); // reset
    for (int i = 0; i < ui->tournamentList->count(); ++i) {
        QListWidgetItem* item = ui->tournamentList->item(i);
        item->setHidden(!item->text().contains(text, Qt::CaseInsensitive));
    }
}
