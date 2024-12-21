#include "Dungeon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

Dungeon::Dungeon() : currentLevel(0), bossRoomUnlocked(false), bossRoomPlaced(false) {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator
    generateDungeon();
    currentRoom = dungeonLevels[currentLevel][0].get();
}

Dungeon::~Dungeon() {
    // No need to manually delete rooms since we are using unique_ptr
}

void Dungeon::generateDungeon() {
    // Define possible room types
    std::vector<std::string> roomTypes = {"treasure", "monster", "puzzle", "trap"};

    for (int level = 0; level < 10; ++level) {
        std::vector<std::unique_ptr<Room>> levelRooms;

        for (int i = 0; i < 3; ++i) {
            int randomIndex = std::rand() % roomTypes.size();
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

        dungeonLevels.push_back(std::move(levelRooms));
    }
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
    for (size_t i = 0; i < 3; ++i) {
        std::cout << i + 1 << ". Go to room " << i + 1 << "\n";
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

    if (choice > 0 && choice <= 3) {
        currentRoom = dungeonLevels[currentLevel][choice - 1].get();
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