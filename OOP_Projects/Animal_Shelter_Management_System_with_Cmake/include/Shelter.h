#ifndef SHELTER_H
#define SHELTER__H

#include <vector>
#include <memory>
#include "Animal.h"

class Shelter {
    private:
        std::vector<std::unique_ptr<Animal>> animals;

    public:
        void addAnimal(std::unique_ptr<Animal> animal);
        void removeAnimal (const std::string &name);
        void listAnimals() const;
        Animal* findAnimal(const std::string &name) const;
};

#endif
