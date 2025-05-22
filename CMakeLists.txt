cmake_minimum_required(VERSION 3.16)

project(PokerTurney LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt 6
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Brug automoc, autouic, autorcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Tilføj include paths
include_directories(include)
include_directories(src)
include_directories(ui)

# Kilde- og headerfiler
set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/database.cpp
    src/tournament.cpp
    src/player.cpp
    src/createtournamentdialog.cpp
    src/addplayerdialog.cpp
)

set(HEADERS
    include/mainwindow.h
    include/database.h
    include/tournament.h
    include/player.h
    include/createtournamentdialog.h
    include/addplayerdialog.h
)

set(UIS
    src/mainwindow.ui
    src/createtournamentdialog.ui
    src/addplayerdialog.ui
)

add_executable(PokerTurney
    ${UIS}
    ${SOURCES}
    ${HEADERS}
)


# Link mod Qt (skal først ske efter add_executable!)
target_link_libraries(PokerTurney
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
