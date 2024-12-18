#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Enemy.h"

class Game; // Forward declaration

class Player
{
public:
    Player(Game &game);
    void displayStats() const;
    void lookAround() const;
    void attack();
    void equip();
    void unequip();
    void drop();
    void pickUp();
    void talkTo();
    void loot();
    void showMenu() const;
    void addItem(const std::string &item);
    void fight(Enemy *enemy);
    void levelUp();
    void showInventory() const;
    void equipItem(const std::string &item);
    void unequipItem();
    void useItem(const std::string &item);

private:
    Game &game;
    int health;
    int level;
    int xp;
    int gold;
    std::vector<std::string> items; // Vector of items
    std::string gear;
    std::string weapon;
    int strength;
    int stamina;
    int agility;
    int intelligence;
    int wisdom;
    int charisma;
    int attackPower;
    int maxHealth;
};

#endif // PLAYER_H