#ifndef SUPER_MUTANT_HPP
# define SUPER_MUTANT_HPP
# include <string>
# include <iostream>
# include "Enemy.hpp"

class SuperMutant : public Enemy
{
    public:
        SuperMutant();
        SuperMutant(SuperMutant const &);
        SuperMutant & operator=(SuperMutant const &);
        ~SuperMutant();

        void takeDamage(int);
};

#endif