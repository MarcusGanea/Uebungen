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
            availableRooms.push_back("treasure");
        } else if (roomTypes[randomIndex] == "boss") {
            rooms["boss"] = std::make_unique<BossRoom>();
            availableRooms.push_back("boss");
        } else if (roomTypes[randomIndex] == "monster") {
            rooms["monster"] = std::make_unique<MonsterRoom>();
            availableRooms.push_back("monster");
        } else if (roomTypes[randomIndex] == "puzzle") {
            rooms["puzzle"] = std::make_unique<PuzzleRoom>();
            availableRooms.push_back("puzzle");
        } else if (roomTypes[randomIndex] == "trap") {
            rooms["trap"] = std::make_unique<TrapRoom>();
            availableRooms.push_back("trap");
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
    for (size_t i = 0; i < availableRooms.size(); ++i) {
        std::cout << i + 1 << ". Go to " << availableRooms[i] << " room\n";
    }
    std::cout << availableRooms.size() + 1 << ". Quit\n";
    std::cout << "=====================\n";
    std::cout << "Enter your choice: ";
}

void Dungeon::handleInput(const std::string &input) {
    int choice;
    std::stringstream(input) >> choice;

    if (choice > 0 && choice <= static_cast<int>(availableRooms.size())) {
        std::string selectedRoom = availableRooms[choice - 1];
        currentRoom = rooms[selectedRoom].get();
        if (selectedRoom == "treasure") {
            bossRoomUnlocked = true; // Unlock boss room after visiting treasure room
        }
    } else if (choice == static_cast<int>(availableRooms.size()) + 1) {
        std::cout << "Quitting the game.\n";
        exit(0);
    } else {
        std::cout << "Invalid choice.\n";
    }
}