#include "Game.h"
#include <iostream>

Game::Game()
{
    player = new Player("Hero");
    initializeRooms();
    currentRoom = rooms[0];
}

Game::~Game()
{
    delete player;
    for (Room *room : rooms)
    {
        delete room;
    }
}

void Game::start()
{
    std::string input;
    while (true)
    {
        currentRoom->enter(*player);
        showMenu();
        std::cin >> input;
        handleInput(input);
    }
}

void Game::initializeRooms()
{
    rooms.push_back(new Room("Starting Room"));
    rooms.push_back(new Room("Treasure Room"));
    rooms.push_back(new Room("Monster Room"));
    rooms.push_back(new Room("Boss Room"));
}

void Game::showMenu()
{
    std::cout << "Menu:\n";
    std::cout << "1. Look Around\n";
    std::cout << "2. Move to another room\n";
    std::cout << "3. Show Stats\n";
    std::cout << "4. Quit\n";
    std::cout << "Enter your choice: ";
}

void Game::handleInput(const std::string &input)
{
    if (input == "1")
    {
        player->lookAround();
    }
    else if (input == "2")
    {
        std::cout << "Choose a room (0-" << rooms.size() - 1 << "): ";
        int roomIndex;
        std::cin >> roomIndex;
        if (roomIndex >= 0 && roomIndex < rooms.size())
        {
            currentRoom = rooms[roomIndex];
        }
        else
        {
            std::cout << "Invalid room number.\n";
        }
    }
    else if (input == "3")
    {
        player->showStats();
    }
    else if (input == "4")
    {
        std::cout << "Quitting the game.\n";
        exit(0);
    }
    else
    {
        std::cout << "Invalid choice.\n";
    }
}