#include <stdio.h>
#include <iostream>
using namespace std;
#include "calc.h"
#include "cal_IO.h"
#include "menu.h"

int main()
{
    menu m;
    m.intro();
    cal_IO cal;
    cal.choose();
    m.outro();
    return 0;
}