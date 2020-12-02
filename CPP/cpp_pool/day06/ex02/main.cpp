#include "BaseA.hpp"
#include "BaseB.hpp"
#include "BaseC.hpp"
#include <iostream>
#include <cstdlib>

Base* createA(void)
{
    return new BaseA;
}

Base* createB(void)
{
    return new BaseB;
}

Base* createC(void)
{
    return new BaseC;
}

Base* generate(void)
{
    Base* (*fct[])(void) = {&createA, &createB, &createC};
    return fct[rand() % 3]();
}

void identify_from_pointer(Base* p)
{
    if (dynamic_cast<BaseA*>(p))
    {
        std::cout << "A" << std::endl;
    }
    if (dynamic_cast<BaseB*>(p))
    {
        std::cout << "B" << std::endl;
    }
    if (dynamic_cast<BaseC*>(p))
    {
        std::cout << "C" << std::endl;
    }
}

void identify_from_reference(Base& p)
{
    identify_from_pointer(&p);
}

int     main()
{
    Base* b;
    for (int i = 0; i < 10; ++i)
    {
        b = generate();
        identify_from_pointer(b);
        identify_from_reference(*b);
        std::cout << "----  ----" << std::endl;
        delete b;
    }
    return 0;
}