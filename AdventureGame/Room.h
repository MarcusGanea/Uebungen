#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room
{
public:
    Room(const std::string &description);
    virtual ~Room() = default;
    virtual void enter();

protected:
    std::string description;
};

class BaseRoom : public Room
{
public:
    BaseRoom();
    void enter() override;
};

class TreasureRoom : public Room
{
public:
    TreasureRoom();
    void enter() override;
};

class MonsterRoom : public Room
{
public:
    MonsterRoom();
    void enter() override;
};

class BossRoom1 : public Room
{
public:
    BossRoom1();
    void enter() override;
};

#endif // ROOM_H