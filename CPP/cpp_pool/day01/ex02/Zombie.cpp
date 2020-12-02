#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) {
    std::cout << "Zombie " << this->_name << " woke up, type of: " << this->_type << std::endl;
}
Zombie::~Zombie() {
    std::cout << "Zombie " << this->_name << " has been killed" << std::endl;
}

void Zombie::advert()
{
    std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiiiinnnnsssss ..." << std::endl;
    return;
}
