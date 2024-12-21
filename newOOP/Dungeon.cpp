#include "Dungeon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

Dungeon::Dungeon() : currentLevel(0), bossRoomUnlocked(false), bossRoomPlaced(false) {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator
    generateDungeon();
    currentRoom = dungeonLevels[0][0].get();
}

Dungeon::~Dungeon() {
    // No need to manually delete rooms since we are using unique_ptr
}

void Dungeon::generateDungeon() {
    // Define possible room types
    std::vector<std::string> roomTypes = {"treasure", "monster", "puzzle", "trap"};

    // Generate the base level
    dungeonLevels.push_back(generateLevel(0, roomTypes));

    // Generate subsequent levels
    for (int level = 1; level < 10; ++level) {
        dungeonLevels.push_back(generateLevel(level, roomTypes));
    }

    // Link rooms to their next level rooms
    for (int level = 0; level < 9; ++level) {
        for (auto& room : dungeonLevels[level]) {
            for (int i = 0; i < 3; ++i) {
                room->addNextRoom(std::make_unique<Room>(*dungeonLevels[level + 1][i]));
            }
        }
    }
}

std::vector<std::unique_ptr<Room>> Dungeon::generateLevel(int level, const std::vector<std::string>& roomTypes) {
    std::vector<std::unique_ptr<Room>> levelRooms;

    for (int i = 0; i < 3; ++i) {
        int randomIndex = std::rand() % roomTypes.size();
        std::string roomName = "Room " + std::to_string(level * 3 + i + 1);
        if (roomTypes[randomIndex] == "treasure") {
            levelRooms.push_back(std::make_unique<TreasureRoom>());
        } else if (roomTypes[randomIndex] == "monster") {
            levelRooms.push_back(std::make_unique<MonsterRoom>());
        } else if (roomTypes[randomIndex] == "puzzle") {
            levelRooms.push_back(std::make_unique<PuzzleRoom>());
        } else if (roomTypes[randomIndex] == "trap") {
            levelRooms.push_back(std::make_unique<TrapRoom>());
        }
    }

    // Place the boss room at a random position in the 10th level if not already placed
    if (level == 9 && !bossRoomPlaced) {
        int bossRoomIndex = std::rand() % 3;
        levelRooms[bossRoomIndex] = std::make_unique<BossRoom>();
        bossRoomPlaced = true;
    }

    return levelRooms;
}

void Dungeon::start() {
    std::string input;
    while (true) {
        currentRoom->enter();
        showMenu();
        std::cin >> input;
        handleInput(input);
    }
}

void Dungeon::showMenu() {
    std::cout << "=====================\n";
    std::cout << "Menu:\n";
    const auto& nextRooms = currentRoom->getNextRooms();
    for (size_t i = 0; i < nextRooms.size(); ++i) {
        std::cout << i + 1 << ". Go to " << nextRooms[i]->getName() << "\n";
    }
    if (currentLevel > 0) {
        std::cout << "4. Go back to previous level\n";
    }
    std::cout << "5. Quit\n";
    std::cout << "=====================\n";
    std::cout << "Enter your choice: ";
}

void Dungeon::handleInput(const std::string &input) {
    int choice;
    std::stringstream(input) >> choice;

    const auto& nextRooms = currentRoom->getNextRooms();
    if (choice > 0 && choice <= static_cast<int>(nextRooms.size())) {
        currentRoom = nextRooms[choice - 1].get();
        if (currentLevel < 9) {
            ++currentLevel;
        }
    } else if (choice == 4 && currentLevel > 0) {
        --currentLevel;
        currentRoom = dungeonLevels[currentLevel][0].get();
    } else if (choice == 5) {
        std::cout << "Quitting the game.\n";
        exit(0);
    } else {
        std::cout << "Invalid choice.\n";
    }
}