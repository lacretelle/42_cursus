#include "AMateria.hpp"

AMateria::AMateria() : _type(""), _xp(0) {}
AMateria::AMateria(std::string const &type) : _type(type), _xp(0) {}
AMateria::AMateria(AMateria const &src)
{
    *this = src;
}
AMateria &AMateria::operator=(AMateria const &src)
{
    this->_xp = src.getXP();
    return *this;
}
AMateria::~AMateria() {}
std::string const &AMateria::getType() const
{
    return this->_type;
}
unsigned int AMateria::getXP() const
{
    return this->_xp;
}
void AMateria::setXP(unsigned int n)
{
    this->_xp += n;
}
