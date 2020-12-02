#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) 
{
    // std::cout << "A PlasmaRifle " << this->_name << " is constructed." << std::endl;
}
PlasmaRifle::PlasmaRifle(PlasmaRifle const & src)
{
    *this = src;
    // std::cout << "A copy of PlasmaRifle " << this->_name << " is copied." << std::endl;
}
PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle const &src)
{
    this->_name = src.getName();
    this->_apcost = src.getAPCost();
    this->_damage = src.getDamage();
    // std::cout << "Assignation operator called" << std::endl;
    return *this;
}
PlasmaRifle::~PlasmaRifle() 
{
    // std::cout << "A PlasmaRifle " << this->getName() << " is destructed." << std::endl;
}
void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}