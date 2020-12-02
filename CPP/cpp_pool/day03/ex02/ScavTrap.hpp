#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &);
        ScavTrap & operator=(ScavTrap const &);
        ~ScavTrap();

        void        challengeNewcomer(void);
        void        challenge1(void);
        void        challenge2(void);
        void        challenge3(void);
        void        challenge4(void);
        void        challenge5(void);
};

#endif