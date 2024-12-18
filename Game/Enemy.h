#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy
{
public:
    Enemy(const std::string &name, int health, int damage);
    void attack();
    bool isAlive() const;
    void takeDamage(int damage);

private:
    std::string name;
    int health;
    int damage;
};

#endif // ENEMY_H