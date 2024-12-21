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