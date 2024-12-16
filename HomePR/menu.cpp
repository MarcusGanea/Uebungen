#include "menu.h"
#include "person.h"
#include <iostream>
#include <string>
#include <limits>

// Function to display the menu
void showMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Add a person\n";
    std::cout << "2. Display person details\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
}

// Function to start the program and handle user interactions
void startProgram() {
    Person person("", 0);
    int choice;

    while (true) {
        showMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        std::string name;
        int age;
        switch (choice) {
        case 1:
            std::cout << "Enter name: ";
            std::cin.ignore(); // To ignore the newline character left by std::cin
            std::getline(std::cin, name);

            std::cout << "Enter age: ";
            std::cin >> age;

            if (std::cin.fail()) {
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                std::cout << "Invalid input. Please enter a valid age.\n";
                continue;
            }

            person = Person(name, age);
            break;
        case 2:
            person.display();
            break;
        case 3:
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}