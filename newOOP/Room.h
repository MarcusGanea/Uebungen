#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

class Room {
public:
    Room(const std::string &description);
    virtual ~Room() = default;
    virtual void enter();
    std::string getDescription() const;

protected:
    std::string description;
};

class BaseRoom : public Room {
public:
    BaseRoom();
    void enter() override;
};

class BossRoom : public Room {
public:
    BossRoom();
    void enter() override;
};

class TreasureRoom : public Room {
public:
    TreasureRoom();
    void enter() override;
};

class MonsterRoom : public Room {
public:
    MonsterRoom();
    void enter() override;
};

class PuzzleRoom : public Room {
public:
    PuzzleRoom();
    void enter() override;
};

class TrapRoom : public Room {
public:
    TrapRoom();
    void enter() override;
};

#endif // ROOM_H