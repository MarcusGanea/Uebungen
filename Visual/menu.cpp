#include <stdio.h>
#include <iostream>

#include "menu.h"
#include "introduction.h"
using namespace std;

Menu::Menu()
{
    cout << "Welcome to the game!" << endl;
}

Menu::~Menu()
{
    cout << "Thanks for playing!" << endl;
}

void Menu::start()
{
    cout << "Starting the game..." << endl;
    introduction();
}