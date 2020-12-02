#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}
Ice::Ice(Ice const & src)
{
    *this = src;
}
Ice & Ice::operator=(Ice const & src)
{
    if (this == &src)
		return (*this);
	AMateria::operator=(src);
	return *this;
}
Ice::~Ice(){}
void        Ice::use(ICharacter & target)
{
    this->setXP(10);
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
AMateria*   Ice::clone() const
{
    return new Ice(*this);
}