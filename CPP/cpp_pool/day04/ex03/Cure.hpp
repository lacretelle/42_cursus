#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
# include <iostream>

class Cure : public AMateria
{
    public:
        Cure();
        Cure(Cure const &);
        Cure & operator=(Cure const &);
        ~Cure();
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif