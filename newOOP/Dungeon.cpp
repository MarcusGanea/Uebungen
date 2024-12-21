#include "Dungeon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

Dungeon::Dungeon() : currentLevel(0), bossRoomUnlocked(false), bossRoomPlaced(false) {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator
    generateDungeon();
    currentRoom = dungeonLevels[0].get();
}

Dungeon::~Dungeon() {
    // No need to manually delete rooms since we are using unique_ptr
}

void Dungeon::generateDungeon() {
    // Define possible room types
    std::vector<std::string> roomTypes = {"treasure", "monster", "puzzle", "trap"};

    // Generate the base level
    dungeonLevels.push_back(std::make_unique<BaseRoom>());

    // Generate subsequent levels
    generateLevel(dungeonLevels[0].get(), 1, roomTypes);
}

void Dungeon::generateLevel(Room* parentRoom, int level, const std::vector<std::string>& roomTypes) {
    if (level > 5) return; // Decrease the maximum number of levels to 5

    for (int i = 0; i < 3; ++i) {
        int randomIndex = std::rand() % roomTypes.size();
        std::unique_ptr<Room> newRoom;
        if (roomTypes[randomIndex] == "treasure") {
            newRoom = std::make_unique<TreasureRoom>();
        } else if (roomTypes[randomIndex] == "monster") {
            newRoom = std::make_unique<MonsterRoom>();
        } else if (roomTypes[randomIndex] == "puzzle") {
            newRoom = std::make_unique<PuzzleRoom>();
        } else if (roomTypes[randomIndex] == "trap") {
            newRoom = std::make_unique<TrapRoom>();
        }

        Room* newRoomPtr = newRoom.get();
        parentRoom->addNextRoom(newRoomPtr);
        dungeonLevels.push_back(std::move(newRoom));

        // Place the boss room at a random position in the 5th level if not already placed
        if (level == 5 && !bossRoomPlaced) {
            int bossRoomIndex = std::rand() % 3;
            if (i == bossRoomIndex) {
                parentRoom->getNextRooms()[i] = new BossRoom();
                bossRoomPlaced = true;
            }
        }

        generateLevel(newRoomPtr, level + 1, roomTypes);
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
        currentRoom = nextRooms[choice - 1];
        if (currentLevel < 5) { // Adjust the maximum level check
            ++currentLevel;
        }
    } else if (choice == 4 && currentLevel > 0) {
        --currentLevel;
        currentRoom = dungeonLevels[currentLevel].get();
    } else if (choice == 5) {
        std::cout << "Quitting the game.\n";
        exit(0);
    } else {
        std::cout << "Invalid choice.\n";
    }
}