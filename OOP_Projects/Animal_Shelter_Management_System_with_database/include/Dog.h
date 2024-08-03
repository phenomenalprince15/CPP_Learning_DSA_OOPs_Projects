#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
    public:
        Dog(const std::string &name, int age, const std::string &breed);
        void sound() const override;
        void bark() const;
};

#endif