#include "Room.h"
#include "Game.h"
#include <iostream>

Room::Room(const std::string &description, const std::string &detailedDescription)
    : description(description), detailedDescription(detailedDescription), enemy(nullptr), looted(false) {}

void Room::enter(Player &player)
{
    std::cout << description << std::endl;
    if (!items.empty() && !looted)
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

void Room::lookAround() const
{
    std::cout << detailedDescription << std::endl;
}

BaseRoom::BaseRoom() : Room("You find yourself in a dark room with three doors.", "This is the dungeon entrance. It's relatively safe here.") {}

void BaseRoom::enter(Player &player)
{
    Room::enter(player);
    std::cout << "Do you want to go through the left door, straight door or the right door?\n";
}

void BaseRoom::lookAround() const
{
    Room::lookAround();
}

TreasureRoom::TreasureRoom() : Room("Dungeon room 0_1 -Treasure Room", "You see a room filled with glittering treasures and valuable items.")
{
    items.push_back("sword +5");
}

void TreasureRoom::enter(Player &player)
{
    Room::enter(player);
    if (!looted)
    {
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
            looted = true;
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
    else
    {
        std::cout << "The room is empty. You have already taken the items.\n";
    }
}

void TreasureRoom::lookAround() const
{
    Room::lookAround();
}

TreasureRoom2::TreasureRoom2() : Room("Dungeon room 0_5 -Treasure Room", "You see a room with a single chest in the center, containing a Health Potion.")
{
    items.push_back("Health Potion");
}

void TreasureRoom2::enter(Player &player)
{
    Room::enter(player);
    if (!looted)
    {
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
            looted = true;
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
    else
    {
        std::cout << "The room is empty. You have already taken the items.\n";
    }
}

void TreasureRoom2::lookAround() const
{
    Room::lookAround();
}

MonsterRoom::MonsterRoom() : Room("Dungeon room 0_2 -Goblin Den", "You sense a dark and foul smell. Maybe you should turn around while you can.")
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
            std::cout << "You ran back to the dungeon entrance.\n";
            player.getGame().setCurrentRoom(0);
        }
        else
        {
            std::cout << "Invalid choice. Please type 'fight' or 'run'.\n";
        }
    }
}

void MonsterRoom::lookAround() const
{
    Room::lookAround();
}

MonsterRoom2::MonsterRoom2() : Room("Dungeon room 0_4 -Tombs", "You see ancient tombs and feel a chilling presence.")
{
    enemy = new Enemy("Skeleton", 50, 5);
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
            std::cout << "You ran back to the dungeon entrance.\n";
            player.getGame().setCurrentRoom(0);
        }
        else
        {
            std::cout << "Invalid choice. Please type 'fight' or 'run'.\n";
        }
    }
}

void MonsterRoom2::lookAround() const
{
    Room::lookAround();
}

MonsterRoom3::MonsterRoom3() : Room("Dungeon room 0_6 -Haunted Chambers", "You hear whispers and see shadows moving in the darkness.")
{
    enemy = new Enemy("Ghost", 50, 10);
}

void MonsterRoom3::enter(Player &player)
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
            std::cout << "You ran back to the dungeon entrance.\n";
            player.getGame().setCurrentRoom(0);
        }
        else
        {
            std::cout << "Invalid choice. Please type 'fight' or 'run'.\n";
        }
    }
}

void MonsterRoom3::lookAround() const
{
    Room::lookAround();
}

MonsterRoom4::MonsterRoom4() : Room("Dungeon room 0_7 - Knight's Room", "You see what must be hundreds of fallen warriors, this was a strong foe.")
{
    enemy = new Enemy("Dark Knight", 70, 15);
}

void MonsterRoom4::enter(Player &player)
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
            std::cout << "You ran back to the dungeon entrance.\n";
            player.getGame().setCurrentRoom(0);
        }
        else
        {
            std::cout << "Invalid choice. Please type 'fight' or 'run'.\n";
        }
    }
}

void MonsterRoom4::lookAround() const
{
    Room::lookAround();
}

BossRoom1::BossRoom1() : Room("You encounter the final boss!", "The air is thick with tension. The final battle awaits.")
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
            std::cout << "You ran back to the dungeon entrance.\n";
            player.getGame().setCurrentRoom(0);
        }
        else
        {
            std::cout << "Invalid choice. Please type 'fight' or 'run'.\n";
        }
    }
}

void BossRoom1::lookAround() const
{
    Room::lookAround();
}