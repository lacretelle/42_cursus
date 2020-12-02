#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() : _hitPoints(60), _maxHitPoints(60), _energyPoints(120), _maxEnergyPoints(120), _level(1), _name("NinjaTrap"),_meleeAttackDamage(60), _rangedAttackDamage(5), _armorDamageReduction(0) {
}
NinjaTrap::NinjaTrap(std::string name) : _hitPoints(60), _maxHitPoints(60), _energyPoints(120), _maxEnergyPoints(120), _level(1), _name(name), _meleeAttackDamage(60), _rangedAttackDamage(5), _armorDamageReduction(0)
{
    std::cout << "Ninja Trap is constructed." << std::endl;
}
NinjaTrap::NinjaTrap(NinjaTrap const &src)
{
    *this = src;
    std::cout << "A copy of Ninja Trap " << this->_name << " is copied." << std::endl;
}
NinjaTrap &NinjaTrap::operator=(NinjaTrap const &ft)
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
NinjaTrap::~NinjaTrap()
{
    std::cout << "Ninja Trap " << this->_name << " is destructed." << std::endl;
}
void NinjaTrap::meleeAttack(std::string const &target)
{
    std::cout << "NinjaTrap " << this->getName() << " attaque " << target << ", causant " << this->getMeleeAttackDamage() << " points de dégâts !" << std::endl;
}
void	NinjaTrap::ninjaShoebox(ClapTrap const & rhs) {
		std::cout << this->_name << " lance ninjaShoebox sur " << rhs.getName();
		std::cout << std::endl << "Hyah!" << std::endl;
	return ;
}
void	NinjaTrap::ninjaShoebox(ScavTrap const & rhs) {
		std::cout << this->_name << " lance ninjaShoebox sur " << rhs.getName();
		std::cout << std::endl << "Heyyah!" << std::endl;
	return ;
}
void	NinjaTrap::ninjaShoebox(FragTrap const & rhs) {
		std::cout << this->_name << " lance ninjaShoebox sur " << rhs.getName();
		std::cout << std::endl << "Bop!" << std::endl;
	return ;
}
void	NinjaTrap::ninjaShoebox(NinjaTrap const & rhs) {
		std::cout << this->_name << " lance ninjaShoebox sur " << rhs.getName();
		std::cout << std::endl << "I'm on a roll!" << std::endl;
	return ;
}

/*
* ASSESSOR GETTER
*/

int NinjaTrap::getHitPoints() const
{
    return this->_hitPoints;
}
int NinjaTrap::getMaxHitPoints() const
{
    return this->_maxHitPoints;
}
int NinjaTrap::getEnergyPoints() const
{
    return this->_energyPoints;
}
int NinjaTrap::getMaxEnergyPoints() const
{
    return this->_maxEnergyPoints;
}
int NinjaTrap::getLevel() const
{
    return this->_level;
}
std::string NinjaTrap::getName() const
{
    return this->_name;
}
int NinjaTrap::getMeleeAttackDamage() const
{
    return this->_meleeAttackDamage;
}
int NinjaTrap::getRangedAttackDamage() const
{
    return this->_rangedAttackDamage;
}
int NinjaTrap::getArmorDamageReduction() const
{
    return this->_armorDamageReduction;
}