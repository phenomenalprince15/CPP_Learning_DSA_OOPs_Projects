#include "Cat.h"
#include <iostream>

Cat::Cat(const std::string &name, int age, const std::string &breed)
    : Animal(name, age, breed) {}

void Cat::sound() const {
    std::cout << name << " say meow!" << std::endl;
}

void Cat::meow() const {
    std::cout << name << " is meowing." << std::endl;
}
