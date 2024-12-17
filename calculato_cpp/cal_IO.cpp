#include <iostream>
using namespace std;
#include <stdio.h>
#include "calc.h"
#include <math.h>
#include "cal_IO.h"

cal_IO::cal_IO()
{
}

cal_IO::~cal_IO()
{
}

void cal_IO::input()
{
    float n1, n2;
    char op;
    cout << "\nEnter first number: ";
    cin >> n1;
    cout << "\nEnter operator: ";
    cin >> op;
    cout << "\nEnter second number: ";
    cin >> n2;
    calc c;
    cout << "Result: " << c.calculate(n1, n2, op) << endl;
}