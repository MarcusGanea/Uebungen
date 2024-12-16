#include "Game.h"
#include <iostream>

Game::Game()
{
    rooms["base"] = new BaseRoom();
    rooms["left"] = new TreasureRoom();
    rooms["right"] = new MonsterRoom();
    rooms["boss"] = new BossRoom1();
    currentRoom = rooms["base"]; // Initialize currentRoom
}

Game::~Game()
{
    for (auto &pair : rooms)
    {
        delete pair.second;
    }
}

void Game::start()
{
    while (true)
    {
        currentRoom->enter(); // Use currentRoom
        std::string choice;
        std::cin >> choice;

        if (rooms.find(choice) != rooms.end())
        {
            currentRoom = rooms[choice]; // Update currentRoom
        }
        else
        {
            std::cout << "Invalid choice. Please type 'left', 'right', 'boss', or 'base'.\n";
        }
    }
}

void Game::showIntroduction()
{
    std::cout << "Welcome to the Adventure Game!\n";
    std::cout << "You find yourself in a dark room with three doors.\n";
    std::cout << "Do you want to go through the left door, straight door or the right door?\n";
}