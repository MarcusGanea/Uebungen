#ifndef ROOM_H
#define ROOM_H

#include "Player.h"
#include "Enemy.h"
#include <string>
#include <vector>

class Room
{
public:
    Room(const std::string &description);
    virtual ~Room() = default;
    virtual void enter(Player &player);

protected:
    std::string description;
    std::vector<std::string> items;
    Enemy *enemy;
    bool looted; // Boolean to check if items have been looted
};

class BaseRoom : public Room
{
public:
    BaseRoom();
    void enter(Player &player) override;
};

class TreasureRoom : public Room
{
public:
    TreasureRoom();
    void enter(Player &player) override;
};

class TreasureRoom2 : public Room
{
public:
    TreasureRoom2();
    void enter(Player &player) override;
};

class MonsterRoom : public Room
{
public:
    MonsterRoom();
    void enter(Player &player) override;
};

class MonsterRoom2 : public Room
{
public:
    MonsterRoom2();
    void enter(Player &player) override;
};

class BossRoom1 : public Room
{
public:
    BossRoom1();
    void enter(Player &player) override;
};

#endif // ROOM_H