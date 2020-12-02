#include "Zombie.hpp"


Zombie::Zombie()
{
    this->_type = "roman soldier";
    std::string zombieName[] = {"lucille", "rick", "negan", "daryl",
                                "glenn", "maggie", "carol", "michonne", "beth", "rosita", "jesus", "morgan", "hershel"};
    std::string name = zombieName[std::rand() % 13];
    this->_name = name;
    std::cout << "Zombie " << this->_name << " woke up, type of: " << this->_type << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->_name << " has been killed" << std::endl;
}

void Zombie::advert()
{
    std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiiiinnnnsssss ..." << std::endl;
    return;
}
