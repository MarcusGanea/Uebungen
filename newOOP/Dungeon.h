#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"
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
    void generateLevel(Room* parentRoom, int level, const std::vector<std::string>& roomTypes);
    std::vector<std::vector<std::unique_ptr<Room>>> dungeonLevels;
    Room* currentRoom;
    int currentLevel;
    bool bossRoomUnlocked;
    bool bossRoomPlaced;
};

#endif // DUNGEON_H