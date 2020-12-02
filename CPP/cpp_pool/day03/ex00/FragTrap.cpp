#include "FragTrap.hpp"

FragTrap::FragTrap()
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
FragTrap::FragTrap(std::string name) : _hitPoints(100), _maxHitPoints(100), _energyPoints(100), _maxEnergyPoints(100), _level(1), _name(name), _meleeAttackDamage(30), _rangedAttackDamage(20), _armorDamageReduction(5)
{
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
    std::cout << "FR4G-TP " << this->getName() << " is destructed." << std::endl;
}
void FragTrap::rangedAttack(std::string const &target)
{
    std::cout << "FR4G-TP " << this->getName() << " attaque " << target << " à distance, causant " << this->getRangedAttackDamage() << " points de dégâts !" << std::endl;
}
void FragTrap::meleeAttack(std::string const &target)
{
    std::cout << "FR4G-TP " << this->getName() << " attaque " << target << ", causant " << this->getMeleeAttackDamage() << " points de dégâts !" << std::endl;
}
void FragTrap::takeDamage(unsigned int amount)
{
    int damage = amount - this->getArmorDamageReduction();
    if (damage < 0)
    {
        std::cout << "This damage is too low ! Nothing happens !" << std::endl;
        return;
    }
    this->_hitPoints -= damage;
    if (this->getHitPoints() < 0)
    {
        this->_hitPoints = 0;
        std::cout << "FR4G-TP " << this->getName() << " n'a plus de points de vie !" << std::endl;
        return;
    }
    std::cout << "FR4G-TP " << this->getName() << " reçoit " << damage << " points de dégâts !"
              << "Il n'est plus qu'à " << this->getHitPoints() << " de points de vie." << std::endl;
}
void FragTrap::beRepaired(unsigned int amount)
{
    int newHitPoints = amount + this->getHitPoints();
    if (newHitPoints > this->getMaxHitPoints())
        this->_hitPoints = this->getMaxHitPoints();
    else
        this->_hitPoints = newHitPoints;
    std::cout << "FR4G-TP " << this->getName() << " guérit, ses points de vie sont maintenant de " << this->getHitPoints() << " !" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
    int attackTab[5] = {1, 2, 3, 4, 5};
    int attack = attackTab[std::rand() % 5];
    if (this->getEnergyPoints() < 25)
        std::cout << "FR4G-TP " << this->getName() << " n'a plus assez d'énergie pour lancer une attaque !!" << std::endl;
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
    std::cout << target << " est touché !" << std::endl;
}
void FragTrap::attack2(std::string const &target)
{
    std::cout << "Ha ha ha! Fall before your robot overlord!" << std::endl;
    std::cout << target << " est touché !" << std::endl;
}
void FragTrap::attack3(std::string const &target)
{
    std::cout << "Oh no, Badass!! " << std::endl;
    std::cout << target << " est touché !" << std::endl;
}
void FragTrap::attack4(std::string const &target)
{
    std::cout << "Throwing grenade!!" << std::endl;
    std::cout << target << " est touché !" << std::endl;
}
void FragTrap::attack5(std::string const &target)
{
    std::cout << "Is it dead? Can, can I open my eyes now?!" << std::endl;
    std::cout << target << " est touché !" << std::endl;
}

/*
* ASSESSOR GETTER
*/

int FragTrap::getHitPoints() const
{
    return this->_hitPoints;
}
int FragTrap::getMaxHitPoints() const
{
    return this->_maxHitPoints;
}
int FragTrap::getEnergyPoints() const
{
    return this->_energyPoints;
}
int FragTrap::getMaxEnergyPoints() const
{
    return this->_maxEnergyPoints;
}
int FragTrap::getLevel() const
{
    return this->_level;
}
std::string FragTrap::getName() const
{
    return this->_name;
}
int FragTrap::getMeleeAttackDamage() const
{
    return this->_meleeAttackDamage;
}
int FragTrap::getRangedAttackDamage() const
{
    return this->_rangedAttackDamage;
}
int FragTrap::getArmorDamageReduction() const
{
    return this->_armorDamageReduction;
}