#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# include <string>
# include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &);
        ClapTrap & operator=(ClapTrap const &);
        ~ClapTrap();

        void        rangedAttack(std::string const & target);
        void        meleeAttack(std::string const & target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);

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