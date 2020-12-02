#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}
ClapTrap::ClapTrap(std::string name) : _name(name)
{
    std::cout << "ClapTrap " << name << " is constructed." << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const &src)
{
    *this = src;
    std::cout << "A copy of ClapTrap " << this->_name << " is copied." << std::endl;
}
ClapTrap &ClapTrap::operator=(ClapTrap const &ft)
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
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " is destructed." << std::endl;
}
void ClapTrap::rangedAttack(std::string const &target)
{
    std::cout << "ClapTrap " << this->getName() << " attaque " << target << " à distance, causant " << this->getRangedAttackDamage() << " points de dégâts !" << std::endl;
}
void ClapTrap::meleeAttack(std::string const &target)
{
    std::cout << "ClapTrap " << this->getName() << " attaque " << target << ", causant " << this->getMeleeAttackDamage() << " points de dégâts !" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    int damage = amount - this->getArmorDamageReduction();
    if (damage < 0)
    {
        std::cout << "This damage is too low ! Nothing happens !" << std::endl;
        return;
    }
    this->_hitPoints -= damage;
    if (this->getHitPoints() < 0)
        this->_hitPoints = 0;
    std::cout << "ClapTrap " << this->getName() << " reçoit " << damage << " points de dégâts !"
              << "Il n'est plus qu'à " << this->getHitPoints() << " de points de vie." << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    int newHitPoints = amount + this->getHitPoints();
    if (newHitPoints > this->getMaxHitPoints())
        this->_hitPoints = this->getMaxHitPoints();
    else
        this->_hitPoints = newHitPoints;
    std::cout << "ClapTrap " << this->getName() << " guérit, ses points de vie sont maintenant de " << this->getHitPoints() << std::endl;
}

/*
* ASSESSOR GETTER
*/

int ClapTrap::getHitPoints() const
{
    return this->_hitPoints;
}
int ClapTrap::getMaxHitPoints() const
{
    return this->_maxHitPoints;
}
int ClapTrap::getEnergyPoints() const
{
    return this->_energyPoints;
}
int ClapTrap::getMaxEnergyPoints() const
{
    return this->_maxEnergyPoints;
}
int ClapTrap::getLevel() const
{
    return this->_level;
}
std::string ClapTrap::getName() const
{
    return this->_name;
}
int ClapTrap::getMeleeAttackDamage() const
{
    return this->_meleeAttackDamage;
}
int ClapTrap::getRangedAttackDamage() const
{
    return this->_rangedAttackDamage;
}
int ClapTrap::getArmorDamageReduction() const
{
    return this->_armorDamageReduction;
}