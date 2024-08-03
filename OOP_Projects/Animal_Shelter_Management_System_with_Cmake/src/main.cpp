#include <iostream>
#include <memory>
#include "Dog.h"
#include "Cat.h"
#include "Bird.h"
#include "Shelter.h"

void showMenu()
{
    std::cout << "\nAnimal Shelter Management System\n";
    std::cout << "1. Add Animal\n";
    std::cout << "2. Remove Animal\n";
    std::cout << "3. List Animals\n";
    std::cout << "4. Find Animal\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your Choice : ";
}

int main()
{
    Shelter shelter;
    int choice;
    std::string name, breed;
    int age;

    while(true)
    {
        showMenu();
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << "Enter animal type (1=Dog, 2=Cat, 3=Bird) : ";
                int type;
                std::cin >> type;
                std::cout << "Enter name : ";
                std::cin >> name;
                std::cout << "Enter age : ";
                std::cin >> age;
                std::cout << "Enter breed : ";
                std::cin >> breed;

                if (type == 1){
                    shelter.addAnimal(std::make_unique<Dog>(name, age, breed));
                } else if (type == 2){
                    shelter.addAnimal(std::make_unique<Cat>(name, age, breed));
                } else if (type == 3){
                    shelter.addAnimal(std::make_unique<Bird>(name, age, breed));
                } else {
                    std::cout << "Invalid type!" << std::endl;
                }
                break;
            
            case 2:
                std::cout << "Enter name of animal to remove : ";
                std::cin >> name;
                shelter.removeAnimal(name);
                break;
            
            case 3:
                shelter.listAnimals();
                break;
            
            case 4:
                std::cout << "Enter name of animal to find : ";
                std::cin >> name;
                if (Animal* animal = shelter.findAnimal(name)){
                    std::cout << "Animal found : " << animal->getName() << ", Breed : " << animal->getBreed()
                    << ", Age : " << animal->getAge() << std::endl;
                    animal->sound();
                } else {
                    std::cout << "Animal not found." << std::endl;
                }
                break;

            case 5:
                return 0;
            
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    }

}
