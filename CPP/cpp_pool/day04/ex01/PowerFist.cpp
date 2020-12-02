#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) 
{
    // std::cout << "A PowerFist " << this->_name << " is constructed." << std::endl;
}
PowerFist::PowerFist(PowerFist const & src)
{
    *this = src;
    // std::cout << "A copy of PowerFist " << this->_name << " is copied." << std::endl;
}
PowerFist &PowerFist::operator=(PowerFist const &src)
{
    this->_name = src.getName();
    this->_apcost = src.getAPCost();
    this->_damage = src.getDamage();
    // std::cout << "Assignation operator called" << std::endl;
    return *this;
}
PowerFist::~PowerFist() 
{
    // std::cout << "A PowerFist " << this->getName() << " is destructed." << std::endl;
}
void PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM ! *" << std::endl;
}