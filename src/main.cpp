#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow w;

    // Load files
    w.db.loadPlayersFromFile("players.csv");
    w.db.loadFromFile("tournaments.csv");

    w.show();

    int result = app.exec();

    // Save on exit
    w.db.savePlayersToFile("players.csv");
    w.db.saveToFile("tournaments.csv");

    return result;
}
