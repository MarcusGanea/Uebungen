#include "Room.h"
#include <iostream>

Room::Room(const std::string &name, const std::string &description) : name(name), description(description) {}

void Room::enter() {
    std::cout << description << std::endl;
}

std::string Room::getDescription() const {
    return description;
}

std::string Room::getName() const {
    return name;
}

BaseRoom::BaseRoom() : Room("Base Room", "You are in the base room.") {}

void BaseRoom::enter() {
    Room::enter();
    std::cout << "There are doors to other rooms.\n";
}

BossRoom::BossRoom() : Room("Boss Room", "You have entered the boss room!") {}

void BossRoom::enter() {
    Room::enter();
    std::cout << "Prepare for a tough battle!\n";
}

TreasureRoom::TreasureRoom() : Room("Treasure Room", "You have found a treasure room!") {}

void TreasureRoom::enter() {
    Room::enter();
    std::cout << "You see a chest filled with gold.\n";
}

MonsterRoom::MonsterRoom() : Room("Monster Room", "You have entered a monster room!") {}

void MonsterRoom::enter() {
    Room::enter();
    std::cout << "A wild monster appears!\n";
}

PuzzleRoom::PuzzleRoom() : Room("Puzzle Room", "You have entered a puzzle room!") {}

void PuzzleRoom::enter() {
    Room::enter();
    std::cout << "Solve the puzzle to proceed.\n";
}

TrapRoom::TrapRoom() : Room("Trap Room", "You have entered a trap room!") {}

void TrapRoom::enter() {
    Room::enter();
    std::cout << "Watch out for traps!\n";
}