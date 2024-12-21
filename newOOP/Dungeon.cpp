#include "Dungeon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream> // Add this include for stringstream

Dungeon::Dungeon() : bossRoomUnlocked(false) {
    generateRooms();
    currentRoom = rooms["base"];
}

Dungeon::~Dungeon() {
    for (auto &pair : rooms) {
        delete pair.second;
    }
}

void Dungeon::generateRooms() {
    rooms["base"] = new BaseRoom();
    rooms["treasure"] = new TreasureRoom();
    rooms["boss"] = new BossRoom();
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
            currentRoom = rooms["treasure"];
            bossRoomUnlocked = true; // Unlock boss room after visiting treasure room
            break;
        case 2:
            if (bossRoomUnlocked) {
                currentRoom = rooms["boss"];
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