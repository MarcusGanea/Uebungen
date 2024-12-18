#ifndef ROOM_H
#define ROOM_H

#include "Player.h"
#include <string>

class Room
{
public:
    Room(const std::string &description);
    virtual void enter(Player &player);

protected:
    std::string description;
};

#endif // ROOM_H