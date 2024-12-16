#include <stdio.h>
#include <iostream>

#include "menu.h"
#include "introduction.h"
using namespace std;

introduction::introduction()
{
    cout << "This journey may be long and perilous, but you will look back and find joy" << endl;
}

introduction::~introduction()
{
    cout << "Good luck on your journey!" << endl;
}