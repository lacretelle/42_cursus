#ifndef SUPER_TRAP_HPP
# define SUPER_TRAP_HPP
# include <iostream>
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
    public:
        SuperTrap();
        SuperTrap(std::string name);
        SuperTrap(SuperTrap const &);
        SuperTrap & operator=(SuperTrap const &);
        ~SuperTrap();

        using FragTrap::rangedAttack;
        using NinjaTrap::meleeAttack;
        using FragTrap::getHitPoints;
        using FragTrap::getMaxHitPoints;
        using NinjaTrap::getEnergyPoints;
        using NinjaTrap::getMaxEnergyPoints;
        using FragTrap::getLevel;
        using FragTrap::getName;
        using NinjaTrap::getMeleeAttackDamage;
        using FragTrap::getRangedAttackDamage;
        using FragTrap::getArmorDamageReduction;

    protected:
        using FragTrap::_hitPoints;
        using FragTrap::_maxHitPoints;
        using NinjaTrap::_energyPoints;
        using NinjaTrap::_maxEnergyPoints;
        using FragTrap::_name;
        using FragTrap::_level;
        using NinjaTrap::_meleeAttackDamage;
        using FragTrap::_rangedAttackDamage;
        using FragTrap::_armorDamageReduction;
};

#endif