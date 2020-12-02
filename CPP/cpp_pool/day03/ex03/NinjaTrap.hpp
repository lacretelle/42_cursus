#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP
# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class NinjaTrap
{
    public:
        NinjaTrap();
        NinjaTrap(std::string name);
        NinjaTrap(NinjaTrap const &);
        NinjaTrap & operator=(NinjaTrap const &);
        ~NinjaTrap();

        void ninjaShoebox(ClapTrap const &rhs);
		void ninjaShoebox(ScavTrap const &rhs);
		void ninjaShoebox(FragTrap const &rhs);
		void ninjaShoebox(NinjaTrap const &rhs);

        int         getHitPoints() const;
        int         getMaxHitPoints() const;
        int         getEnergyPoints() const;
        int         getMaxEnergyPoints() const;
        int         getLevel() const;
        std::string getName() const;
        int         getMeleeAttackDamage() const;
        int         getRangedAttackDamage() const;
        int         getArmorDamageReduction() const;

    protected:
        int         _hitPoints;
        int         _maxHitPoints;
        int         _energyPoints;
        int         _maxEnergyPoints;
        int         _level;
        std::string _name;
        int         _meleeAttackDamage;
        int         _rangedAttackDamage;
        int         _armorDamageReduction;
};

#endif