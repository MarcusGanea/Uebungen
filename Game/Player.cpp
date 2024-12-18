#include "Player.h"
#include <iostream>

Player::Player(const std::string &name)
    : name(name), health(100), level(1), xp(0), gold(0) {}

void Player::lookAround() const
{
    std::cout << "You look around the room.\n";
}

void Player::showStats() const
{
    std::cout << "Name: " << name << "\n";
    std::cout << "Health: " << health << "\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "XP: " << xp << "\n";
    std::cout << "Gold: " << gold << "\n";
    std::cout << "Inventory: ";
    for (const std::string &item : inventory)
    {
        std::cout << item << " ";
    }
    std::cout << "\n";
}