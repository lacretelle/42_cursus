#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->_name = "ScavTrap";
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
ScavTrap::ScavTrap(std::string name) : _hitPoints(100), _maxHitPoints(100), _energyPoints(50), _maxEnergyPoints(50), _level(1), _name(name), _meleeAttackDamage(20), _rangedAttackDamage(15), _armorDamageReduction(3)
{
    std::cout << "ScavTrap " << name << " is constructed." << std::endl;
}
ScavTrap::ScavTrap(ScavTrap const &src)
{
    *this = src;
    std::cout << "A copy of ScavTrap " << this->_name << " is copied." << std::endl;
}
ScavTrap &ScavTrap::operator=(ScavTrap const &ft)
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
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " is destructed." << std::endl;
}
void ScavTrap::rangedAttack(std::string const &target)
{
    std::cout << "ScavTrap " << this->getName() << " attaque " << target << " à distance, causant " << this->getRangedAttackDamage() << " points de dégâts !" << std::endl;
}
void ScavTrap::meleeAttack(std::string const &target)
{
    std::cout << "ScavTrap " << this->getName() << " attaque " << target << ", causant " << this->getMeleeAttackDamage() << " points de dégâts !" << std::endl;
}
void ScavTrap::takeDamage(unsigned int amount)
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
        std::cout << "ScavTrap " << this->getName() << " n'a plus de points de vie !" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->getName() << " reçoit " << damage << " points de dégâts !"
              << "Il n'est plus qu'à " << this->getHitPoints() << " de points de vie." << std::endl;
}
void ScavTrap::beRepaired(unsigned int amount)
{
    int newHitPoints = amount + this->getHitPoints();
    if (newHitPoints > this->getMaxHitPoints())
        this->_hitPoints = this->getMaxHitPoints();
    else
        this->_hitPoints = newHitPoints;
    std::cout << "ScavTrap " << this->getName() << " guérit, ses points de vie sont maintenant de " << this->getHitPoints() << " !" << std::endl;
}

void ScavTrap::challengeNewcomer(void)
{
    int n;
    std::cout << "Choose your challenge, enter a number between 1 and 5, inclusive" << std::endl;
    std::cin >> n;
    while (n < 1 || n > 5)
    {
        std::cout << "Your input is not valide, enter a number between 1 and 5 !" << std::endl;
        std::cin >> n;
    }
    if (n == 1)
        this->challenge1();
    else if (n == 2)
        this->challenge2();
    else if (n == 3)
        this->challenge3();
    else if (n == 4)
        this->challenge4();
    else if (n == 5)
        this->challenge5();
    return;
}

void ScavTrap::challenge1()
{
    std::cout << "Rase toi la tete !" << std::endl;
}
void ScavTrap::challenge2()
{
    std::cout << "Fais 50 pompes !" << std::endl;
}
void ScavTrap::challenge3()
{
    std::cout << "Raconte moi une bonne blague." << std::endl;
}
void ScavTrap::challenge4()
{
    std::cout << "Chante une chanson de celine dion !" << std::endl;
}
void ScavTrap::challenge5()
{
    std::cout << "Mets plus de 10 petits beurres dans ta bouche en même temps !" << std::endl;
}

/*
* ASSESSOR GETTER
*/

int ScavTrap::getHitPoints() const
{
    return this->_hitPoints;
}
int ScavTrap::getMaxHitPoints() const
{
    return this->_maxHitPoints;
}
int ScavTrap::getEnergyPoints() const
{
    return this->_energyPoints;
}
int ScavTrap::getMaxEnergyPoints() const
{
    return this->_maxEnergyPoints;
}
int ScavTrap::getLevel() const
{
    return this->_level;
}
std::string ScavTrap::getName() const
{
    return this->_name;
}
int ScavTrap::getMeleeAttackDamage() const
{
    return this->_meleeAttackDamage;
}
int ScavTrap::getRangedAttackDamage() const
{
    return this->_rangedAttackDamage;
}
int ScavTrap::getArmorDamageReduction() const
{
    return this->_armorDamageReduction;
}