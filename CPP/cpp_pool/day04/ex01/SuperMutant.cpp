#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Break everything !" << std::endl;
}
SuperMutant::SuperMutant(SuperMutant const &src)
{
    *this = src;
    // std::cout << "A copy of SuperMutant is copied." << std::endl;
}
SuperMutant & SuperMutant::operator=(SuperMutant const &src)
{
    this->_hp = src.getHP();
    this->_type = src.getType();
    // std::cout << "Assignation operator called" << std::endl;
    return *this;
}
SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh ..." << std::endl;
}
void SuperMutant::takeDamage(int n)
{
    if (n > 0)
    {
        n -= 3;
        this->_hp -= n;
        if (this->getHP() < 0)
            this->_hp = 0;
        // std::cout << "An SuperMutant takes " << n << "damages" << std::endl;
    }
}