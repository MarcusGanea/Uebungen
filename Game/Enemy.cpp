#include "Enemy.h"
#include <iostream>

Enemy::Enemy(const std::string &name, int health, int damage)
    : name(name), health(health), damage(damage) {}

void Enemy::attack()
{
    std::cout << name << " attacks for " << damage << " damage!\n";
}

bool Enemy::isAlive() const
{
    return health > 0;
}

void Enemy::takeDamage(int damage)
{
    health -= damage;
    if (health < 0)
        health = 0;
    std::cout << name << " takes " << damage << " damage, health is now " << health << ".\n";
}

std::string Enemy::getName() const
{
    return name;
}

int Enemy::getDamage() const
{
    return damage;
}

int Enemy::getXpReward() const
{
    return health / 2; // Example XP reward calculation
}