#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Enemy.h"

class Player
{
public:
    Player();
    void displayStats() const;
    void lookAround() const;
    void attack();
    void equip();
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

private:
    int health;
    int level;
    int xp;
    int gold;
    std::vector<std::string> items;
    std::string gear;
    std::string weapon;
    int strength;
    int stamina;
    int agility;
    int intelligence;
    int wisdom;
    int charisma;
    int attackPower;
};

#endif // PLAYER_H