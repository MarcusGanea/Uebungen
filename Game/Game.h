#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Room.h"
#include <vector>
#include <string>

class Game
{
public:
    Game();
    ~Game();
    void start();
    void initializeRooms();
    void showMenu();
    void handleInput(const std::string &input);
    void gameOver();
    void displayIntro() const;
    void displayOutro(); // Add this method
    Room *getCurrentRoom() const;
    void setCurrentRoom(int roomIndex);

private:
    Player *player;
    std::vector<Room *> rooms; // Vector of rooms
    Room *currentRoom;
};

#endif // GAME_H