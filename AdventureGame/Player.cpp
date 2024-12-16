#include "Player.h"
#include <iostream>

Player::Player()
    : health(100), level(1), xp(0), gold(0), gear("None"), weapon("None"),
      strength(10), stamina(10), agility(10), intelligence(10), wisdom(10), charisma(10) {}

void Player::displayStats() const
{
    std::cout << "Health: " << health << "\n"
              << "Level: " << level << "\n"
              << "XP: " << xp << "\n"
              << "Gold: " << gold << "\n"
              << "Gear: " << gear << "\n"
              << "Weapon: " << weapon << "\n"
              << "Strength: " << strength << "\n"
              << "Stamina: " << stamina << "\n"
              << "Agility: " << agility << "\n"
              << "Intelligence: " << intelligence << "\n"
              << "Wisdom: " << wisdom << "\n"
              << "Charisma: " << charisma << "\n";
}

void Player::lookAround() const
{
    std::cout << "You look around the room.\n";
}

void Player::attack()
{
    std::cout << "You attack with your " << weapon << ".\n";
}

void Player::equip()
{
    std::cout << "You equip an item.\n";
}

void Player::drop()
{
    std::cout << "You drop an item.\n";
}

void Player::pickUp()
{
    std::cout << "You pick up an item.\n";
}

void Player::talkTo()
{
    std::cout << "You talk to someone.\n";
}

void Player::loot()
{
    std::cout << "You loot the area.\n";
}

void Player::showMenu() const
{
    std::cout << "Menu:\n"
              << "1. Look Around\n"
              << "2. Attack\n"
              << "3. Equip\n"
              << "4. Drop\n"
              << "5. Pick Up\n"
              << "6. Talk To\n"
              << "7. Loot\n"
              << "8. Show Stats\n"
              << "9. Help\n";
}