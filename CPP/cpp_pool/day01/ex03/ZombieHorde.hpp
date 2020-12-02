#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP
# include <string>
# include <iostream>
# include "Zombie.hpp"

class ZombieHorde
{
public:
    ZombieHorde(int n);
    ~ZombieHorde(void);
    void    announce(void);
private:
    int     _n;
    Zombie* _horde;
};
#endif