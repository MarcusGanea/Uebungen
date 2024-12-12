#include "Game.h"
#include <iostream>

Game::Game()
{
    rooms["left"] = new TreasureRoom();
    rooms["right"] = new MonsterRoom();
    rooms["straight"] = new BossRoom1();
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
    showIntroduction();
    std::string choice;
    std::cin >> choice;

    if (rooms.find(choice) != rooms.end())
    {
        rooms[choice]->enter();
    }
    else
    {
        std::cout << "Invalid choice. Please type 'left' or 'right'.\n";
    }
}

void Game::showIntroduction()
{
    std::cout << "Welcome to the Adventure Game!\n";
    std::cout << "You find yourself in a dark room with two doors.\n";
    std::cout << "Do you want to go through the left door, straight door or the right door?\n";
}