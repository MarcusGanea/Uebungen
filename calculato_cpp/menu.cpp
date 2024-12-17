#include <iostream>
using namespace std;
#include <stdio.h>
#include "menu.h"
#include "cal_IO.h"

menu::menu()
{
}

menu::~menu()
{
}

void menu::intro()
{
    cout << "Welcome to the calculator" << endl;
}

void menu::display()
{

    cout << "Please choose wisely" << endl;
    cout << "===========================" << endl;
    cout << "1. calculation" << endl;
    cout << "2. Exit" << endl;
    cout << "===========================" << endl;
}
