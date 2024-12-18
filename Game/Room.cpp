#include "Room.h"
#include <iostream>

Room::Room(const std::string &description) : description(description), enemy(nullptr) {}

void Room::enter(Player &player)
{
    std::cout << description << std::endl;
    if (!items.empty())
    {
        std::cout << "You see: ";
        for (const auto &item : items)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    if (enemy && enemy->isAlive())
    {
        std::cout << "You encounter an enemy: " << enemy->getName() << std::endl;
    }
}

BaseRoom::BaseRoom() : Room("You find yourself in a dark room with three doors.") {}

void BaseRoom::enter(Player &player)
{
    Room::enter(player);
    std::cout << "Do you want to go through the left door, straight door or the right door?\n";
}

TreasureRoom::TreasureRoom() : Room("Dungeon room 0_1 -Treasure Room")
{
    items.push_back("sword (+5 Attack on Equip)");
}

void TreasureRoom::enter(Player &player)
{
    Room::enter(player);
    std::cout << "Do you want to take the items or leave them?\n";
    std::string choice;
    std::cin >> choice;

    if (choice == "take")
    {
        for (const auto &item : items)
        {
            player.addItem(item);
        }
        items.clear();
        std::cout << "You take the items.\n";
    }
    else if (choice == "leave")
    {
        std::cout << "You leave the items and exit the room.\n";
    }
    else
    {
        std::cout << "Invalid choice. Please type 'take' or 'leave'.\n";
    }
}

MonsterRoom::MonsterRoom() : Room("Dungeon room 0_2 -Goblin Den")
{
    enemy = new Enemy("Goblin", 30, 5);
}

void MonsterRoom::enter(Player &player)
{
    Room::enter(player);
    if (enemy && enemy->isAlive())
    {
        std::cout << "The monster attacks you! Do you want to fight or run?\n";
        std::string choice;
        std::cin >> choice;

        if (choice == "fight")
        {
            player.fight(enemy);
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
}

MonsterRoom2::MonsterRoom2() : Room("Dungeon room 0_4 -Tombs")
{
    enemy = new Enemy("Skeleton", 40, 5);
}

void MonsterRoom2::enter(Player &player)
{
    Room::enter(player);
    if (enemy && enemy->isAlive())
    {
        std::cout << "The monster attacks you! Do you want to fight or run?\n";
        std::string choice;
        std::cin >> choice;

        if (choice == "fight")
        {
            player.fight(enemy);
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
}

BossRoom1::BossRoom1() : Room("Boss Room 0_1 - The Dragon")
{
    enemy = new Enemy("Dragon", 100, 20);
}

void BossRoom1::enter(Player &player)
{
    Room::enter(player);
    if (enemy && enemy->isAlive())
    {
        std::cout << "Do you want to fight the boss or run away?\n";
        std::string choice;
        std::cin >> choice;

        if (choice == "fight")
        {
            player.fight(enemy);
        }
        else if (choice == "run")
        {
            std::cout << "You run away safely, but the game continues.\n";
        }
        else
        {
            std::cout << "Invalid choice. Please type 'fight' or 'run'.\n";
        }
    }
}