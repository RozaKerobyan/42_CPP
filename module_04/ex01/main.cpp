#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n===== BASIC POLYMORPHISM TEST =====\n";

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "\n===== DELETION TEST (virtual destructor) =====\n";
    delete meta;
    delete j;
    delete i;

    std::cout << "\n===== WRONG ANIMAL TEST (NO PROPER POLYMORPHISM) =====\n";

    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << std::endl;

    wrong->makeSound();
    wrongCat->makeSound();
    delete wrong;
    delete wrongCat;

    std::cout << "\n===== DEEP COPY TEST (Brain) =====\n";

    Cat original;
    original.getBrain()->setIdea(0, "I want fish");
    original.getBrain()->setIdea(1, "I want sleep");

    Cat copy = original;

    std::cout << "Original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea[0]: " << copy.getBrain()->getIdea(0) << std::endl;

    copy.getBrain()->setIdea(0, "I am copied cat");

    std::cout << "After modification:\n";
    std::cout << "Original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea[0]: " << copy.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n===== ASSIGNMENT OPERATOR TEST =====\n";

    Cat a;
    Cat b;

    a.getBrain()->setIdea(0, "A idea");

    b = a;

    std::cout << "A: " << a.getBrain()->getIdea(0) << std::endl;
    std::cout << "B: " << b.getBrain()->getIdea(0) << std::endl;

    b.getBrain()->setIdea(0, "B changed");

    std::cout << "After change:\n";
    std::cout << "A: " << a.getBrain()->getIdea(0) << std::endl;
    std::cout << "B: " << b.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n===== END TEST =====\n";
    return 0;
}