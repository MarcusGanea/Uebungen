#include "Room.h"
#include <iostream>

Room::Room(const std::string &description) : description(description) {}

void Room::enter(Player &player)
{
    std::cout << description << std::endl;
}