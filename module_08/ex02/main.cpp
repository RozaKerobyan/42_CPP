#include "MutantStack.hpp"

int main()
{

    std::cout << "---- Test from subject ----" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "---- Test 1: test with top() and size() ----" << std::endl;
    {
        MutantStack<int> mstack_2;

        mstack_2.push(10);
        mstack_2.push(20);
        mstack_2.push(30);

        std::cout << "top: " << mstack_2.top() << std::endl;
        std::cout << "size: " << mstack_2.size() << std::endl;

        mstack_2.pop();

        std::cout << "top after pop: " << mstack_2.top() << std::endl;
        std::cout << "size after pop: " << mstack_2.size() << std::endl;
    }
    std::cout << "---- Test 2: iterator ----" << std::endl;
    {
        MutantStack<int> mstack_1;

        mstack_1.push(10);
        mstack_1.push(20);
        mstack_1.push(30);

        for (MutantStack<int>::iterator it = mstack_1.begin(); it != mstack_1.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
    }
    std::cout << "---- Test 3: const iterator ----" << std::endl;
    {
        MutantStack<int> mstack_3;

        mstack_3.push(10);
        mstack_3.push(20);
        mstack_3.push(30);

        const MutantStack<int> mstack_3_const(mstack_3);

        MutantStack<int>::const_iterator it = mstack_3_const.begin();
        MutantStack<int>::const_iterator ite = mstack_3_const.end();

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    std::cout << "---- Test 4: reverse iterator ----" << std::endl;
    {
        MutantStack<int> mstack_4;

        mstack_4.push(10);
        mstack_4.push(20);
        mstack_4.push(30);
        mstack_4.push(40);

        MutantStack<int>::reverse_iterator it = mstack_4.rbegin();
        MutantStack<int>::reverse_iterator ite = mstack_4.rend();

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    std::cout << "---- Test 5: const reverse iterator ----" << std::endl;
    {
        MutantStack<int> mstack_5;

        mstack_5.push(10);
        mstack_5.push(20);
        mstack_5.push(30);
        mstack_5.push(40);

        const MutantStack<int> mstack_5_const(mstack_5);

        MutantStack<int>::const_reverse_iterator it = mstack_5_const.rbegin();
        MutantStack<int>::const_reverse_iterator ite = mstack_5_const.rend();

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    std::cout << "---- Test 6: ++it and --it ----" << std::endl;
    {
        MutantStack<int> mstack_6;

        mstack_6.push(10);
        mstack_6.push(20);
        mstack_6.push(30);

        MutantStack<int>::iterator it = mstack_6.begin();

        std::cout << *it << std::endl;

        ++it;
        std::cout << *it << std::endl;

        ++it;
        std::cout << *it << std::endl;

        --it;
        std::cout << *it << std::endl;

        --it;
        std::cout << *it << std::endl;
    }
    std::cout << "---- Test 7: string iterator ----" << std::endl;
    {
        MutantStack<std::string> mstack_7;

        mstack_7.push("Hello");
        mstack_7.push("42Yerevan");
        mstack_7.push("Akhalkalak!");

        for (MutantStack<std::string>::iterator it = mstack_7.begin(); it != mstack_7.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
    }
    return 0;
}