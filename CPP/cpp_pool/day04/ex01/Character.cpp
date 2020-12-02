#include "Character.hpp"

Character::Character() {}
Character::Character(std::string const &name) : _name(name), _ap(40)
{
    // std::cout << "A Character " << this->_name << " is constructed." << std::endl;
}
Character::Character(Character const &src)
{
    *this = src;
    // std::cout << "A copy of Character " << this->_name << " is copied." << std::endl;
}
Character &Character::operator=(Character const &src)
{
    this->_name = src.getName();
    this->_ap = src.getAP();
    this->_weapon = src.getAWeapon();
    // std::cout << "Assignation operator called" << std::endl;
    return *this;
}
Character::~Character()
{
    // std::cout << "A Character " << this->getName() << " is destructed." << std::endl;
}

void Character::recoverAP()
{
    if (this->getAP() > 30)
        this->_ap = 40;
    else
        this->_ap += 10;
}
void Character::equip(AWeapon *wp)
{
    this->_weapon = wp;
}
void Character::attack(Enemy *enemy)
{
    if (this->_weapon != NULL)
    {
        if (this->getAP() >= this->_weapon->getAPCost())
        {
            std::cout << this->getName() << " attaque " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;

            this->_weapon->attack();
            enemy->takeDamage(this->_weapon->getDamage());
            if (enemy->getHP() <= 0)
                delete enemy;
            this->_ap -= this->_weapon->getAPCost();
        }
    }
}

std::string Character::getName() const
{
    return this->_name;
}
int Character::getAP() const
{
    return this->_ap;
}
AWeapon *Character::getAWeapon() const
{
    return this->_weapon;
}

std::ostream & operator<<(std::ostream &o, Character const c)
{
    if (c.getAWeapon() != NULL)
    {
        o << c.getName() << " has " << c.getAP() << " AP and carries a " << c.getAWeapon()->getName() << std::endl;
    }
    else
    {
        o << c.getName() << " has " << c.getAP() << " AP and is unarmed" << std::endl;
    }
    return o;
}