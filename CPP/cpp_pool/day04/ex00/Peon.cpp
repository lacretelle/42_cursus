#include "Peon.hpp"

Peon::Peon(){}
Peon::Peon(std::string name) : Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}
Peon::Peon(Peon const &src)
{
    *this = src;
    std::cout << "A copy of Peon " << this->_name << " is copied." << std::endl;
}
Peon &Peon::operator=(Peon const &src)
{
    this->_name = src.getName();
    std::cout << "Assignation operator called" << std::endl;
    return *this;
}
Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}
std::ostream & operator<<(std::ostream & o, Peon const &s)
{
    o << "I am " << s.getName() << " and I like otters!" << std::endl;
    return o;
}
void        Peon::getPolymorphed() const
{
    std::cout << this->getName() << " was just polymorphed into a pink pony!" << std::endl;
}