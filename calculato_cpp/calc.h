#ifndef CALC_H
#define CALC_H
#include <iostream>
using namespace std;
#include <stdio.h>

class calc
{
private:
    float n1, n2;
    char op;

public:
    calc();
    float calculate(float n1, float n2, char op);
    ~calc();
};

#endif // CALC_H