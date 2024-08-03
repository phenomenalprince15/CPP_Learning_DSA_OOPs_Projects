#include "Shelter.h"
#include <iostream>
#include <algorithm>

void Shelter::addAnimal(std::unique_ptr<Animal> animal){
    animals.push_back(std::move(animal));
}

void Shelter::removeAnimal(const std::string &name){
    auto it = std::remove_if(animals.begin(), animals.end(),
    [&name](const std::unique_ptr<Animal> &animal){
        return animal->getName() == name;
    });

    if (it != animals.end()){
        animals.erase(it, animals.end());
        std::cout << "Animal removed successfully." << std::endl;
    }else{
        std::cout << "Animals not found." << std::endl;
    }
}

void Shelter::listAnimals() const {
    for (const auto &animal : animals){
        std::cout << "Name : " << animal->getName() << " , Breed : " << animal->getBreed()
        << " , Age : " << animal->getAge() << std::endl;
        animal->sound();
    }
}

Animal* Shelter::findAnimal(const std::string &name) const{
    for (const auto &animal : animals){
        if (animal->getName() == name){
            return animal.get();
        }
    }
    return nullptr;
}
