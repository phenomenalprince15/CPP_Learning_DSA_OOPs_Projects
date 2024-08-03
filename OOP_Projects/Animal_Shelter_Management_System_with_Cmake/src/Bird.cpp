#include "Bird.h"
#include <iostream>

Bird::Bird(const std::string &name, int age, const std::string &breed)
    : Animal(name, age, breed) {}

void Bird::sound() const {
    std::cout << name << " say chirp!" << std::endl;
}

void Bird::chirp() const {
    std::cout << name << " is chirping." << std::endl;
}
