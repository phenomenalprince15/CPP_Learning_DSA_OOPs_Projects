#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

// Base class for Animal
class Animal {
public:
    Animal(const std::string& name, int age, const std::string& breed)
        : name(name), age(age), breed(breed) {}

    virtual ~Animal() = default;

    virtual void sound() const = 0;

    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getBreed() const { return breed; }

private:
    std::string name;
    int age;
    std::string breed;
};

// Derived class for Dog
class Dog : public Animal {
public:
    Dog(const std::string& name, int age, const std::string& breed)
        : Animal(name, age, breed) {}

    void sound() const override {
        std::cout << getName() << " says: Woof!" << std::endl;
    }
};

// Derived class for Cat
class Cat : public Animal {
public:
    Cat(const std::string& name, int age, const std::string& breed)
        : Animal(name, age, breed) {}

    void sound() const override {
        std::cout << getName() << " says: Meow!" << std::endl;
    }
};

// Derived class for Bird
class Bird : public Animal {
public:
    Bird(const std::string& name, int age, const std::string& breed)
        : Animal(name, age, breed) {}

    void sound() const override {
        std::cout << getName() << " says: Chirp!" << std::endl;
    }
};

// Shelter class to manage animals
class Shelter {
public:
    void addAnimal(std::unique_ptr<Animal> animal) {
        animals.push_back(std::move(animal));
    }

    void removeAnimal(const std::string& name) {
        auto it = std::remove_if(animals.begin(), animals.end(),
            [&name](const std::unique_ptr<Animal>& animal) {
                return animal->getName() == name;
            });
        if (it != animals.end()) {
            std::cout << (*it)->getName() << " has been removed from the shelter." << std::endl;
            animals.erase(it, animals.end());
        } else {
            std::cout << name << " not found in the shelter." << std::endl;
        }
    }

    void listAnimals() const {
        if (animals.empty()) {
            std::cout << "No animals in the shelter." << std::endl;
        } else {
            for (const auto& animal : animals) {
                std::cout << "Name: " << animal->getName()
                    << ", Age: " << animal->getAge()
                    << ", Breed: " << animal->getBreed() << std::endl;
                animal->sound();
            }
        }
    }

private:
    std::vector<std::unique_ptr<Animal>> animals;
};

int main() {
    Shelter shelter;

    std::string choice;
    while (true) {
        std::cout << "\nAnimal Shelter Management\n";
        std::cout << "1. Add Dog\n";
        std::cout << "2. Add Cat\n";
        std::cout << "3. Add Bird\n";
        std::cout << "4. List Animals\n";
        std::cout << "5. Remove Animal\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == "1" || choice == "2" || choice == "3") {
            std::string name, breed;
            int age;
            std::cout << "Enter animal's name: ";
            std::cin >> name;
            std::cout << "Enter animal's age: ";
            std::cin >> age;
            std::cout << "Enter animal's breed: ";
            std::cin >> breed;

            if (choice == "1") {
                shelter.addAnimal(std::make_unique<Dog>(name, age, breed));
                std::cout << "Dog added successfully!\n";
            } else if (choice == "2") {
                shelter.addAnimal(std::make_unique<Cat>(name, age, breed));
                std::cout << "Cat added successfully!\n";
            } else if (choice == "3") {
                shelter.addAnimal(std::make_unique<Bird>(name, age, breed));
                std::cout << "Bird added successfully!\n";
            }
        } else if (choice == "4") {
            shelter.listAnimals();
        } else if (choice == "5") {
            std::string name;
            std::cout << "Enter the name of the animal to remove: ";
            std::cin >> name;

            shelter.removeAnimal(name);
        } else if (choice == "6") {
            std::cout << "Exiting...\n";
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
