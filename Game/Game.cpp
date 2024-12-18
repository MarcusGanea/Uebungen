#include "Game.h"
#include <iostream>

Game::Game()
{
    player = new Player();
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
    rooms.push_back(new BaseRoom());
    rooms.push_back(new TreasureRoom());
    rooms.push_back(new MonsterRoom());
    rooms.push_back(new BossRoom1());
    rooms.push_back(new MonsterRoom2());
}

void Game::showMenu()
{
    std::cout << "=====================\n";
    std::cout << "Menu:\n";
    std::cout << "1. Look Around\n";
    std::cout << "2. Move to another room\n";
    std::cout << "3. Show Stats\n";
    std::cout << "4. Equip Item\n";
    std::cout << "5. Quit\n";
    std::cout << "=====================\n";
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
        player->displayStats();
    }
    else if (input == "4")
    {
        std::cout << "Inventory:\n";
        player->showInventory();
        std::cout << "Enter the name of the item to equip: ";
        std::string item;
        std::cin.ignore();
        std::getline(std::cin, item);
        player->equipItem(item);
    }
    else if (input == "5")
    {
        std::cout << "Quitting the game.\n";
        exit(0);
    }
    else
    {
        std::cout << "Invalid choice.\n";
    }
}