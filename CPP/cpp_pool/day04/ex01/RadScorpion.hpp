#ifndef RAD_SCORPION_HPP
# define RAD_SCORPION_HPP
# include <string>
# include <iostream>
# include "Enemy.hpp"

class RadScorpion : public Enemy
{
    public:
        RadScorpion();
        RadScorpion(RadScorpion const &);
        RadScorpion & operator=(RadScorpion const &);
        ~RadScorpion();

        void takeDamage(int);
};

#endif