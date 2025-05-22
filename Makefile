CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = src/main.cpp src/player.cpp src/tournament.cpp src/database.cpp

TARGET = poker_manager

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
