#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <vector>

class Enemy
{
public:
    Enemy(const std::string &name, int health, int strength, int stamina);
    void displayStats() const;
    bool isAlive() const;
    void takeDamage(int damage);
    std::vector<std::string> getLoot() const;

private:
    std::string name;
    int health;
    int strength;
    int stamina;
    std::vector<std::string> loot;
};

#endif // ENEMY_H