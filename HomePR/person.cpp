#include "person.h"

// Constructor implementation
Person::Person(const std::string& name, int age) : name(name), age(age) {}

// Member function to display person details
void Person::display() const {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
}