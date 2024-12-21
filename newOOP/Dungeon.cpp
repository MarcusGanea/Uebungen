#include "Dungeon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

Dungeon::Dungeon() : bossRoomUnlocked(false) {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator
    generateRooms();
    currentRoom = rooms["base"].get();
}

Dungeon::~Dungeon() {
    // No need to manually delete rooms since we are using unique_ptr
}

void Dungeon::generateRooms() {
    rooms["base"] = std::make_unique<BaseRoom>();

    // Define possible room types
    std::vector<std::string> roomTypes = {"treasure", "boss", "monster", "puzzle", "trap"};

    // Randomly generate rooms
    for (const auto &roomType : roomTypes) {
        int randomIndex = std::rand() % roomTypes.size();
        if (roomTypes[randomIndex] == "treasure") {
            rooms["treasure"] = std::make_unique<TreasureRoom>();
        } else if (roomTypes[randomIndex] == "boss") {
            rooms["boss"] = std::make_unique<BossRoom>();
        } else if (roomTypes[randomIndex] == "monster") {
            rooms["monster"] = std::make_unique<MonsterRoom>();
        } else if (roomTypes[randomIndex] == "puzzle") {
            rooms["puzzle"] = std::make_unique<PuzzleRoom>();
        } else if (roomTypes[randomIndex] == "trap") {
            rooms["trap"] = std::make_unique<TrapRoom>();
        }
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
    std::cout << "1. Go to treasure room\n";
    if (bossRoomUnlocked) {
        std::cout << "2. Go to boss room\n";
    }
    std::cout << "3. Quit\n";
    std::cout << "=====================\n";
    std::cout << "Enter your choice: ";
}

void Dungeon::handleInput(const std::string &input) {
    int choice;
    std::stringstream(input) >> choice;

    switch (choice) {
        case 1:
            currentRoom = rooms["treasure"].get();
            bossRoomUnlocked = true; // Unlock boss room after visiting treasure room
            break;
        case 2:
            if (bossRoomUnlocked) {
                currentRoom = rooms["boss"].get();
            } else {
                std::cout << "Boss room is locked.\n";
            }
            break;
        case 3:
            std::cout << "Quitting the game.\n";
            exit(0);
        default:
            std::cout << "Invalid choice.\n";
            break;
    }
}