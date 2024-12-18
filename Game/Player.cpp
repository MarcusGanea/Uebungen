#include "Player.h"
#include "Game.h"
#include <iostream>
#include <algorithm>

Player::Player(Game &game)
    : game(game), health(100), level(1), xp(0), gold(0), gear("None"), weapon("None"),
      strength(10), stamina(10), agility(10), intelligence(10), wisdom(10), charisma(10), attackPower(10), maxHealth(100)
{
    items.clear(); // Clear items vector when a new game starts
}

void Player::displayStats() const
{
    std::cout << "Health: " << health << "\n"
              << "Level: " << level << "\n"
              << "XP: " << xp << " (" << (level * 100 - xp) << " XP to level " << (level + 1) << ")\n"
              << "Gold: " << gold << "\n"
              << "Gear: " << gear << "\n"
              << "Weapon: " << weapon << "\n"
              << "Strength: " << strength << "\n"
              << "Stamina: " << stamina << "\n"
              << "Agility: " << agility << "\n"
              << "Intelligence: " << intelligence << "\n"
              << "Wisdom: " << wisdom << "\n"
              << "Charisma: " << charisma << "\n"
              << "Attack Power: " << attackPower << "\n";
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

void Player::unequip()
{
    std::cout << "You unequip an item.\n";
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
              << "4. Unequip\n"
              << "5. Drop\n"
              << "6. Pick Up\n"
              << "7. Talk To\n"
              << "8. Loot\n"
              << "9. Show Stats\n"
              << "10. Show Inventory\n"
              << "11. Use Item\n"
              << "12. Help\n";
}

void Player::addItem(const std::string &item)
{
    items.push_back(item);
    std::cout << "You picked up: " << item << std::endl;
}

void Player::fight(Enemy *enemy)
{
    int xpGained = enemy->getXpReward();
    while (enemy->isAlive() && health > 0)
    {
        std::cout << "You attack the " << enemy->getName() << " for " << attackPower << " damage.\n";
        enemy->takeDamage(attackPower);
        if (enemy->isAlive())
        {
            std::cout << "The " << enemy->getName() << " attacks you for " << enemy->getDamage() << " damage.\n";
            health -= enemy->getDamage();
            if (health <= 0)
            {
                std::cout << "You have been defeated.\n";
                game.gameOver();
                return;
            }
        }
        else
        {
            std::cout << "You have defeated the " << enemy->getName() << "!\n";

            xp += xpGained;
            std::cout << xpGained << " XP gained (" << (level * 100 - xp) << " XP to level " << (level + 1) << ")\n";
            if (xp >= level * 100)
            {
                levelUp();
            }
        }
    }
}

void Player::levelUp()
{
    level++;
    maxHealth += 10;
    health = maxHealth;
    attackPower += 10;
    strength += 10;
    stamina += 10;
    agility += 10;
    intelligence += 10;
    wisdom += 10;
    charisma += 10;
    std::cout << "Congratulations! You have reached level " << level << ".\n";
}

void Player::showInventory() const
{
    std::cout << "Inventory:\n";
    for (const auto &item : items)
    {
        std::cout << "- " << item << "\n";
    }
}

void Player::equipItem(const std::string &item)
{
    if (item == "sword +5")
    {
        if (weapon != "None")
        {
            unequipItem();
        }
        weapon = "sword +5";
        attackPower += 5;
        std::cout << "You equipped the sword. Your attack power is now " << attackPower << ".\n";
    }
    else
    {
        std::cout << "You can't equip that item.\n";
    }
}

void Player::unequipItem()
{
    if (weapon == "sword +5")
    {
        attackPower -= 5;
        std::cout << "You unequipped the sword. Your attack power is now " << attackPower << ".\n";
        weapon = "None";
    }
    else
    {
        std::cout << "You don't have any item equipped.\n";
    }
}

void Player::useItem(const std::string &item)
{
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end())
    {
        if (item == "Health Potion")
        {
            health += 50;
            if (health > maxHealth)
            {
                health = maxHealth;
            }
            std::cout << "You used a Health Potion. Your health is now " << health << ".\n";
            items.erase(it);
        }
        else
        {
            std::cout << "You can't use that item.\n";
        }
    }
    else
    {
        std::cout << "You don't have that item in your inventory.\n";
    }
}