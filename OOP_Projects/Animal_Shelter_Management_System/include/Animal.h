#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
    public:
        Animal(const std::string &name, int age, const std::string &breed);
        virtual ~Animal() = default;

        virtual void sound() const = 0;

        std::string getName() const;
        int getAge() const;
        std::string getBreed() const;

        protected:
            std::string name;
            int age;
            std::string breed;
};

#endif
