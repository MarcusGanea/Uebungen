#include "Room.h"
#include <iostream>

Room::Room(const std::string &description) : description(description) {}

void Room::enter() {
    std::cout << description << std::endl;
}

std::string Room::getDescription() const {
    return description;
}

BaseRoom::BaseRoom() : Room("You are in the base room.") {}

void BaseRoom::enter() {
    Room::enter();
    std::cout << "There are doors to other rooms.\n";
}

BossRoom::BossRoom() : Room("You have entered the boss room!") {}

void BossRoom::enter() {
    Room::enter();
    std::cout << "Prepare for a tough battle!\n";
}

TreasureRoom::TreasureRoom() : Room("You have found a treasure room!") {}

void TreasureRoom::enter() {
    Room::enter();
    std::cout << "You see a chest filled with gold.\n";
}

MonsterRoom::MonsterRoom() : Room("You have entered a monster room!") {}

void MonsterRoom::enter() {
    Room::enter();
    std::cout << "A wild monster appears!\n";
}

PuzzleRoom::PuzzleRoom() : Room("You have entered a puzzle room!") {}

void PuzzleRoom::enter() {
    Room::enter();
    std::cout << "Solve the puzzle to proceed.\n";
}

TrapRoom::TrapRoom() : Room("You have entered a trap room!") {}

void TrapRoom::enter() {
    Room::enter();
    std::cout << "Watch out for traps!\n";
}