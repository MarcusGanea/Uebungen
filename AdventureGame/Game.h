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
};

#endif // GAME_H