#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"
#include <map>
#include <string>
#include <vector>
#include <memory>

class Dungeon {
public:
    Dungeon();
    ~Dungeon();
    void start();
    void generateRooms();
    void showMenu();
    void handleInput(const std::string &input);

private:
    std::map<std::string, std::unique_ptr<Room>> rooms;
    std::vector<std::string> availableRooms;
    Room *currentRoom;
    bool bossRoomUnlocked;
};

#endif // DUNGEON_H