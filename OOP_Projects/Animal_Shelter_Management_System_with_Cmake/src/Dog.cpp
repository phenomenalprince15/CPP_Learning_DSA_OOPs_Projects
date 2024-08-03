#include "Dog.h"
#include <iostream>

Dog::Dog(const std::string &name, int age, const std::string &breed)
    : Animal(name, age, breed) {}

void Dog::sound() const {
    std::cout << name << " is Woof!" << std::endl;
}

void Dog::bark() const {
    std::cout << name << " is barking." << std::endl;
}
