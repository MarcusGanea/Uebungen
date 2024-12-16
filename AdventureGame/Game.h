#ifndef GAME_H
#define GAME_H

#include "Room.h"
#include <map>
#include <string>

class Game
{
public:
    Game();
    ~Game();
    void start();

private:
    void showIntroduction();
    std::map<std::string, Room *> rooms;
    Room *currentRoom; // Declare currentRoom here
};

#endif // GAME_H