#include "SuperTrap.hpp"

SuperTrap::SuperTrap() : FragTrap(), NinjaTrap()
{
    this->_name = "SuperTrap";
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 50;
    this->_maxEnergyPoints = 50;
    this->_level = 1;
    this->_meleeAttackDamage = 20;
    this->_rangedAttackDamage = 15;
    this->_armorDamageReduction = 3;
    std::cout << "ScavTrap " << this->_name << " is constructed." << std::endl;
}
SuperTrap::SuperTrap(std::string name) : FragTrap(name), NinjaTrap()
{
    this->_hitPoints = 100;
    this->_maxHitPoints = 100;
    this->_energyPoints = 50;
    this->_maxEnergyPoints = 50;
    this->_level = 1;
    this->_meleeAttackDamage = 20;
    this->_rangedAttackDamage = 15;
    this->_armorDamageReduction = 3;
    std::cout << "ScavTrap " << this->_name << " is constructed." << std::endl;
}
SuperTrap::SuperTrap(SuperTrap const & src)
{
    *this = src;
}
SuperTrap & SuperTrap::operator=(SuperTrap const & src)
{
    this->_name = src.getName();
    this->_hitPoints = src.getHitPoints();
    this->_maxHitPoints = src.getMaxHitPoints();
    this->_energyPoints = src.getEnergyPoints();
    this->_maxEnergyPoints = src.getMaxEnergyPoints();
    this->_level = src.getLevel();
    this->_meleeAttackDamage = src.getMeleeAttackDamage();
    this->_rangedAttackDamage = src.getRangedAttackDamage();
    this->_armorDamageReduction = src.getArmorDamageReduction();
    std::cout << "ScavTrap " << this->getName() << " is copied." << std::endl;
    return *this;
}
SuperTrap::~SuperTrap()
{
    std::cout << "ScavTrap " << this->getName() << " is destructed." << std::endl;
}