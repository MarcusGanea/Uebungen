#include "Game.h"
#include <iostream>
#include <string>

Game::Game()
{
    player = new Player(*this);
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
    displayIntro();
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
    rooms.push_back(new TreasureRoom2());
    rooms.push_back(new MonsterRoom3());
    rooms.push_back(new MonsterRoom4());
}

void Game::showMenu()
{
    std::cout << "=====================\n";
    std::cout << "Menu:\n";
    std::cout << "1. Look Around\n";
    std::cout << "2. Move to another room\n";
    std::cout << "3. Show Stats\n";
    std::cout << "4. Equip Item\n";
    std::cout << "5. Unequip Item\n";
    std::cout << "6. Show Inventory\n";
    std::cout << "7. Use Item\n";
    std::cout << "8. Quit\n";
    std::cout << "=====================\n";
    std::cout << "Enter your choice: ";
}

void Game::handleInput(const std::string &input)
{
    if (input == "1")
    {
        currentRoom->lookAround();
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
        player->unequipItem();
    }
    else if (input == "6")
    {
        player->showInventory();
    }
    else if (input == "7")
    {
        std::cout << "Inventory:\n";
        player->showInventory();
        std::cout << "Enter the name of the item to use: ";
        std::string item;
        std::cin.ignore();
        std::getline(std::cin, item);
        player->useItem(item);
    }
    else if (input == "8")
    {
        std::cout << "Quitting the game.\n";
        exit(0);
    }
    else
    {
        std::cout << "Invalid choice.\n";
    }
}

void Game::gameOver()
{
    std::cout << "Game Over!\n";
    std::cout << "1. Start a new game\n";
    std::cout << "2. Quit\n";
    std::cout << "Enter your choice: ";
    std::string choice;
    std::cin >> choice;
    if (choice == "1")
    {
        delete player;
        player = new Player(*this);

        // Clear and delete old rooms
        for (Room *room : rooms)
        {
            delete room;
        }
        rooms.clear();

        initializeRooms();
        currentRoom = rooms[0];
        start();
    }
    else if (choice == "2")
    {
        std::cout << "Quitting the game.\n";
        exit(0);
    }
    else
    {
        std::cout << "Invalid choice.\n";
        gameOver();
    }
}

void Game::displayIntro() const
{
    std::cout << R"(
                            ,-.
       ___,---.__          /'|`\          __,---,___
    ,-'    \`    `-.____,-'  |  `-.____,-'    //    `-.
  ,'        |           ~'\     /`~           |        `.
 /      ___//              `. ,'          ,  , \___      \
|    ,-'   `-.__   _         |        ,    __,-'   `-.    |
|   /          /\_  `   .    |    ,      _/\          \   |
\  |           \ \`-.___ \   |   / ___,-'/ /           |  /
 \  \           | `._   `\\  |  //'   _,' |           /  /
  `-.\         /'  _ `---'' , . ``---' _  `\         /,-'
     ``       /     \    ,='/ \`=.    /     \       ''
             |__   /|\_,--.,-.--,--._/|\   __|
             /  `./  \\`\ |  |  | /,//' \,'  \
            /   /     ||--+--|--+-/-|     \   \
           |   |     /'\_\_\ | /_/_/`\     |   |
            \   \__, \_     `~'     _/ .__/   /
             `-._,-'   `-._______,-'   `-._,-'
    )" << std::endl;

    std::cout << "Welcome to the Adventure Game!\n";
    std::cout << "Press Enter to start the game...";
    std::cin.ignore();
    std::cin.get();
}

Room *Game::getCurrentRoom() const
{
    return currentRoom;
}

void Game::setCurrentRoom(int roomIndex)
{
    if (roomIndex >= 0 && roomIndex < rooms.size())
    {
        currentRoom = rooms[roomIndex];
    }
}