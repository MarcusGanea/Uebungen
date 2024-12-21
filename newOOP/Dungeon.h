#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"
#include <map>
#include <string>

class Dungeon {
public:
    Dungeon();
    ~Dungeon();
    void start();
    void generateRooms();
    void showMenu();
    void handleInput(const std::string &input);

private:
    std::map<std::string, Room *> rooms;
    Room *currentRoom;
    bool bossRoomUnlocked;
};

#endif // DUNGEON_H