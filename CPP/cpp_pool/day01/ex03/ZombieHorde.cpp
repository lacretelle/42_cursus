#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) : _n(n)
{
    this->_horde = new Zombie [n];
    std::cout << "ZombieHorde is activated !" << std::endl;
}

ZombieHorde::~ZombieHorde(void)
{
    std::cout << "enter in destructor" << std::endl;
    delete [] this->_horde;
    std::cout << "ZombieHorde is desactivated !" << std::endl;
}

void ZombieHorde::announce()
{
    int i = 0;
    while (i < this->_n)
    {
        this->_horde[i].advert();
        i++;
    }
}