#include "Animal.h"

Animal::Animal(const std::string &n, int a, const std::string &b) {
    name = n;
    age = a;
    breed = b;
}

std::string Animal::getName() const {
    return name;
}
int Animal::getAge() const {
    return age;
}

std::string Animal::getBreed() const {
    return breed;
}
