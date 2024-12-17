#include <iostream>
using namespace std;
#include <stdio.h>
#include "calc.h"
#include <math.h>

calc::calc()
{
}

calc::~calc()
{
}

float calc::calculate(float n1, float n2, char op)
{
    float result;
    switch (op)
    {
    case '+':
        result = n1 + n2;
        break;
    case '-':
        result = n1 - n2;
        break;
    case '*':
        result = n1 * n2;
        break;
    case '/':
        if (n2 != 0)
            return n1 / n2;
        else
        {
            std::cerr << "Error: Division by zero!" << std::endl;
            return 0;
        }
    case '^':
        result = pow(n1, n2);
        break;
    default:
        cout << "Invalid operator\n";
        break;
    }
    return result;
}