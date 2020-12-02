#include "Victim.hpp"

Victim::Victim(){}
Victim::Victim(std::string name) : _name(name)
{
    std::cout << "A random victim called " << name << " just appeared!" << std::endl;
}
Victim::Victim(Victim const &src)
{
    *this = src;
    std::cout << "A copy of Victim " << this->_name << " is copied." << std::endl;
}
Victim &Victim::operator=(Victim const &src)
{
    this->_name = src.getName();
    std::cout << "Assignation operator called" << std::endl;
    return *this;
}
Victim::~Victim()
{
    std::cout << "The victim " << this->getName() << " died for no apparent reasons!" << std::endl;
}
std::ostream & operator<<(std::ostream & o, Victim const &s)
{
    o << "I am " << s.getName() << " and I like otters!" << std::endl;
    return o;
}
std::string Victim::getName() const
{
    return this->_name;
}
void        Victim::getPolymorphed() const
{
    std::cout << this->getName() << " was just polymorphed in a cute little sheep!" << std::endl;
}