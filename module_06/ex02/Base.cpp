#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *generate(void)
{
    int random = std::rand() % 3;

    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Pointer: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer: C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Reference: A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {

    }
    
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Reference: B" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
       
    }
    

    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Reference: C" << std::endl;
        return ;
    }
    catch (const std::exception& e)
    {

    }
}
