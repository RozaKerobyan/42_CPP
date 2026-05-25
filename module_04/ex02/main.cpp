#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n===== ABSTRACT CLASS TEST =====\n";

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\n===== TYPE CHECK =====\n";
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    std::cout << "\n===== POLYMORPHISM TEST =====\n";
    dog->makeSound();
    cat->makeSound();

    std::cout << "\n===== DEEP COPY TEST (Brain) =====\n";

    Cat original;
    original.getBrain()->setIdea(0, "I want fish");
    original.getBrain()->setIdea(1, "I want sleep");

    Cat copy = original;

    std::cout << "Original idea[0]: " << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea[0]: " << copy.getBrain()->getIdea(0) << std::endl;

    copy.getBrain()->setIdea(0, "I am copy cat");

    std::cout << "\nAfter modification:\n";
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

    std::cout << "\nAfter change:\n";
    std::cout << "A: " << a.getBrain()->getIdea(0) << std::endl;
    std::cout << "B: " << b.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n===== POLYMORPHIC ARRAY TEST =====\n";

    const Animal* animals[4];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();

    std::cout << "\n===== CLEANUP TEST =====\n";

    for (int i = 0; i < 4; i++)
        delete animals[i];

    delete dog;
    delete cat;

    std::cout << "\n===== END TEST =====\n";
    return 0;
}