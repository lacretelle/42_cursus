#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# include <string>
# include <iostream>

class ScavTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &);
        ScavTrap & operator=(ScavTrap const &);
        ~ScavTrap();

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

        void        challengeNewcomer(void);
        void        challenge1(void);
        void        challenge2(void);
        void        challenge3(void);
        void        challenge4(void);
        void        challenge5(void);

    private:
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