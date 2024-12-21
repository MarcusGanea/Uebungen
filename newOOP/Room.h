#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <memory>

class Room {
public:
    Room(const std::string &name, const std::string &description);
    virtual ~Room() = default;
    virtual void enter();
    std::string getDescription() const;
    std::string getName() const;
    void addNextRoom(Room* room);
    const std::vector<Room*>& getNextRooms() const;

protected:
    std::string name;
    std::string description;
    std::vector<Room*> nextRooms;
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