#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include <iostream>

class Ice : public AMateria
{
    public:
        Ice();
        Ice(Ice const &);
        Ice & operator=(Ice const &);
        ~Ice();
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif