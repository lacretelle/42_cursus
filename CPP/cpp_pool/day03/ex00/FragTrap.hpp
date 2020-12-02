#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP
# include <string>
# include <iostream>

class FragTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const &);
        FragTrap & operator=(FragTrap const &);
        ~FragTrap();

        void        rangedAttack(std::string const & target);
        void        meleeAttack(std::string const & target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
        void        vaulthunter_dot_exe(std::string const & target);
        int         getHitPoints() const;
        int         getMaxHitPoints() const;
        int         getEnergyPoints() const;
        int         getMaxEnergyPoints() const;
        int         getLevel() const;
        std::string getName() const;
        int         getMeleeAttackDamage() const;
        int         getRangedAttackDamage() const;
        int         getArmorDamageReduction() const;

        void        attack1(std::string const &target);
        void        attack2(std::string const &target);
        void        attack3(std::string const &target);
        void        attack4(std::string const &target);
        void        attack5(std::string const &target);

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