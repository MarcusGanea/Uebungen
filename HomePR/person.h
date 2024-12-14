#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
public:
    std::string name;
    int age;

    // Constructor
    Person(const std::string& name, int age);

    // Member function to display person details
    void display() const;
};

#endif // PERSON_H