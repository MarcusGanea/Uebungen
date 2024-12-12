#include "Room.h"
#include <iostream>

Room::Room(const std::string &description) : description(description) {}

void Room::enter()
{
    std::cout << description << std::endl;
}

TreasureRoom::TreasureRoom() : Room("You find a treasure chest!") {}

void TreasureRoom::enter()
{
    Room::enter();
    std::cout << "Do you want to take the coins or leave them?\n";
    std::string choice;
    std::cin >> choice;

    if (choice == "take")
    {
        std::cout << "You take the coins and become rich!\n";
    }
    else if (choice == "leave")
    {
        std::cout << "You leave the coins and exit the room.\n";
    }
    else
    {
        std::cout << "Invalid choice. Please type 'take' or 'leave'.\n";
    }
}

MonsterRoom::MonsterRoom() : Room("You encounter a monster!") {}

void MonsterRoom::enter()
{
    Room::enter();
    std::cout << "The monster attacks you! Do you want to fight or run?\n";
    std::string choice;
    std::cin >> choice;

    if (choice == "fight")
    {
        std::cout << "You bravely fight the monster and win!\n";
    }
    else if (choice == "run")
    {
        std::cout << "You run away safely.\n";
    }
    else
    {
        std::cout << "Invalid choice. Please type 'fight' or 'run'.\n";
    }
}