#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Room.h"
#include <vector>

class Game
{
public:
    Game();
    ~Game();
    void start();

private:
    void initializeRooms();
    void showMenu();
    void handleInput(const std::string &input);

    Player *player;
    std::vector<Room *> rooms;
    Room *currentRoom;
};

#endif // GAME_H