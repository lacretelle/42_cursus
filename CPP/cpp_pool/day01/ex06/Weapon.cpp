#include "Weapon.hpp"

Weapon::Weapon(){}
Weapon::Weapon(std::string type) : _type(type)
{
    std::cout << "Weapon with type: " << type << " is created" << std::endl;
}
Weapon::~Weapon(void)
{
    std::cout << "Weapon destructed" << std::endl;
}

std::string const & Weapon::getType()
{
    return this->_type;
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}
