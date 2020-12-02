#include "AWeapon.hpp"

AWeapon::AWeapon(){}
AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _name(name), _apcost(apcost), _damage(damage) 
{
    // std::cout << "A AWeapon " << this->_name << " is constructed." << std::endl;
}
AWeapon::AWeapon(AWeapon const &src)
{
    *this = src;
    // std::cout << "A copy of AWeapon " << this->_name << " is copied." << std::endl;
}
AWeapon &AWeapon::operator=(AWeapon const &src)
{
    this->_name = src.getName();
    this->_apcost = src.getAPCost();
    this->_damage = src.getDamage();
    // std::cout << "Assignation operator called" << std::endl;
    return *this;
}
AWeapon::~AWeapon() 
{
    // std::cout << "A AWeapon " << this->getName() << " is destructed." << std::endl;
}

std::string AWeapon::getName() const
{
    return this->_name;
}
int AWeapon::getAPCost() const
{
    return this->_apcost;
}
int AWeapon::getDamage() const
{
    return this->_damage;
}