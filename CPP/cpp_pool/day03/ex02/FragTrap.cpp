#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_name = "FragTrap";
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 100;
    this->_maxEnergyPoints = 100;
    this->_level = 1;
    this->_meleeAttackDamage = 30;
    this->_rangedAttackDamage = 20;
    this->_armorDamageReduction = 5;
    std::cout << "FR4G-TP " << this->_name << " is constructed." << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 100;
    this->_maxEnergyPoints = 100;
    this->_level = 1;
    this->_meleeAttackDamage = 30;
    this->_rangedAttackDamage = 20;
    this->_armorDamageReduction = 5;
    std::cout << "FR4G-TP " << name << " is constructed." << std::endl;
}
FragTrap::FragTrap(FragTrap const &src)
{
    *this = src;
    std::cout << "A copy of FR4G-TP " << this->_name << " is copied." << std::endl;
}
FragTrap &FragTrap::operator=(FragTrap const &ft)
{
    this->_hitPoints = ft.getHitPoints();
    this->_maxHitPoints = ft.getMaxHitPoints();
    this->_energyPoints = ft.getEnergyPoints();
    this->_maxEnergyPoints = ft.getMaxEnergyPoints();
    this->_level = ft.getLevel();
    this->_name = ft.getName();
    this->_meleeAttackDamage = ft.getMeleeAttackDamage();
    this->_rangedAttackDamage = ft.getRangedAttackDamage();
    this->_armorDamageReduction = ft.getArmorDamageReduction();
    std::cout << "Assignation operator called" << std::endl;
    return *this;
}
FragTrap::~FragTrap()
{
    std::cout << "FR4G-TP " << this->_name << " is destructed." << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
    int attackTab[5] = {1, 2, 3, 4, 5};
    int attack = attackTab[std::rand() % 5];
    if (this->getEnergyPoints() < 25)
        std::cout << "FR4G-TP " << this->_name << " n'a plus assez d'énergie pour lancer une attaque !!" << std::endl;
    else
    {
        this->_energyPoints -= 25;
        if (attack == 1)
            this->attack1(target);
        else if (attack == 2)
            this->attack2(target);
        else if (attack == 3)
            this->attack3(target);
        else if (attack == 4)
            this->attack4(target);
        else
            this->attack5(target);
    }
}

void FragTrap::attack1(std::string const &target)
{
    std::cout << "RUN FOR YOUR LIIIIIVES!!! Hyah!" << std::endl;
    this->meleeAttack(target);
}
void FragTrap::attack2(std::string const &target)
{
    std::cout << "Ha ha ha! Fall before your robot overlord!" << std::endl;
    this->rangedAttack(target);
}
void FragTrap::attack3(std::string const &target)
{
    std::cout << "Oh no, Badass!! " << std::endl;
    this->meleeAttack(target);
}
void FragTrap::attack4(std::string const &target)
{
    std::cout << "Throwing grenade!!" << std::endl;
    this->rangedAttack(target);
}
void FragTrap::attack5(std::string const &target)
{
    std::cout << "Is it dead? Can, can I open my eyes now?!" << std::endl;
    this->meleeAttack(target);
}