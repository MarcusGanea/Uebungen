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
    void generateDungeon();
    void showMenu();
    void handleInput(const std::string &input);

private:
    std::vector<std::vector<std::unique_ptr<Room>>> dungeonLevels;
    std::vector<std::string> availableRooms;
    Room *currentRoom;
    int currentLevel;
    bool bossRoomUnlocked;
    bool bossRoomPlaced;
};

#endif // DUNGEON_H