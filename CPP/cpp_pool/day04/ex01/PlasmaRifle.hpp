#ifndef PLASMA_RIFLE_HPP
# define PLASMA_RIFLE_HPP
# include <string>
# include <iostream>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
    public:
        PlasmaRifle();
        PlasmaRifle(PlasmaRifle const &);
        PlasmaRifle & operator=(PlasmaRifle const &);
        ~PlasmaRifle();

        void    attack() const;
};

#endif