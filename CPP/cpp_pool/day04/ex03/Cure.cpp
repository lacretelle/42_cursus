#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}
Cure::Cure(Cure const & src)
{
    *this = src;
}
Cure & Cure::operator=(Cure const & src)
{
   if (this == &src)
		return (*this);
	AMateria::operator=(src);
	return *this;
}
Cure::~Cure(){}
void        Cure::use(ICharacter & target)
{
    this->setXP(10);
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
AMateria*   Cure::clone() const
{
    return new Cure(*this);
}