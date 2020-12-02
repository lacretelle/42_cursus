#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;

}
RadScorpion::RadScorpion(RadScorpion const &src)
{
    *this = src;
    // std::cout << "A copy of RadScorpion is copied." << std::endl;
}
RadScorpion & RadScorpion::operator=(RadScorpion const &src)
{
    this->_hp = src.getHP();
    this->_type = src.getType();
    // std::cout << "Assignation operator called" << std::endl;
    return *this;
}
RadScorpion::~RadScorpion()
{
    std::cout << "* SPROTCH *" << std::endl;
}
void RadScorpion::takeDamage(int n)
{
     if (n > 0)
    {
        this->_hp -= n;
        if (this->getHP() < 0)
            this->_hp = 0;
        // std::cout << "An SuperMutant takes " << n << "damages" << std::endl;
    }
}