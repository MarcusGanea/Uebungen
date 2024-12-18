#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player
{
public:
    Player(const std::string &name);
    void lookAround() const;
    void showStats() const;

private:
    std::string name;
    int health;
    int level;
    int xp;
    int gold;
    std::vector<std::string> inventory;
};

#endif // PLAYER_H