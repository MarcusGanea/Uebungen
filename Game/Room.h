#ifndef ROOM_H
#define ROOM_H

#include "Player.h"
#include "Enemy.h"
#include <string>
#include <vector>

class Room
{
public:
    Room(const std::string &description, const std::string &detailedDescription);
    virtual ~Room() = default;
    virtual void enter(Player &player);
    virtual void lookAround() const;

protected:
    std::string description;
    std::string detailedDescription;
    std::vector<std::string> items;
    Enemy *enemy;
    bool looted; // Boolean to check if items have been looted
};

class BaseRoom : public Room
{
public:
    BaseRoom();
    void enter(Player &player) override;
    void lookAround() const override;
};

// Treasure Rooms
class TreasureRoom : public Room
{
public:
    TreasureRoom();
    void enter(Player &player) override;
    void lookAround() const override;
};

class TreasureRoom2 : public Room
{
public:
    TreasureRoom2();
    void enter(Player &player) override;
    void lookAround() const override;
};

// Monster Rooms
class MonsterRoom : public Room
{
public:
    MonsterRoom();
    void enter(Player &player) override;
    void lookAround() const override;
};

class MonsterRoom2 : public Room
{
public:
    MonsterRoom2();
    void enter(Player &player) override;
    void lookAround() const override;
};

class MonsterRoom3 : public Room
{
public:
    MonsterRoom3();
    void enter(Player &player) override;
    void lookAround() const override;
};

class MonsterRoom4 : public Room
{
public:
    MonsterRoom4();
    void enter(Player &player) override;
    void lookAround() const override;
};

// Boss Rooms
class BossRoom1 : public Room
{
public:
    BossRoom1();
    void enter(Player &player) override;
    void lookAround() const override;
};

#endif // ROOM_H