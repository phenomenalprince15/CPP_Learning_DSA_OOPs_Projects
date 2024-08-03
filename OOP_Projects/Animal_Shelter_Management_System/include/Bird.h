#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal {
    public:
        Bird(const std::string &name, int age, const std::string &breed);
        void sound() const override;
        void chirp() const;
};

#endif