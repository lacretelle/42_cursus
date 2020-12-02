#include "Sorcerer.hpp"

Sorcerer::Sorcerer(){}
Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
    std::cout << name << ", " << title << ", is born !" << std::endl;
}
Sorcerer::Sorcerer(Sorcerer const &src)
{
    *this = src;
    std::cout << "A copy of sorcerer " << this->_name << " is copied." << std::endl;
}
Sorcerer &Sorcerer::operator=(Sorcerer const &src)
{
    this->_name = src.getName();
    this->_title = src.getTitle();
    std::cout << "Assignation operator called" << std::endl;
    return *this;
}
Sorcerer::~Sorcerer()
{
    std::cout << this->getName() << ", " << this->getTitle() << ", is dead.  Consequences will never be the same!" << std::endl;
}
std::ostream & operator<<(std::ostream & o, Sorcerer const &s)
{
    o << "I am " << s.getName() << ", " << s.getTitle() << ", and i like ponies !" << std::endl;
    return o;
}

std::string Sorcerer::getName() const
{
    return this->_name;
}
std::string Sorcerer::getTitle() const
{
    return this->_title;
}
void        Sorcerer::polymorph(Victim const & victim) const
{
    victim.getPolymorphed();
}