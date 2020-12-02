#include "Enemy.hpp"

Enemy::Enemy(){}
Enemy::Enemy(int hp, std::string const &type) : _hp(hp), _type(type)
{
    // std::cout << "An Enemy is constructed." << std::endl;
}
Enemy::Enemy(Enemy const &src)
{
    *this = src;
    // std::cout << "A copy of Enemy is copied." << std::endl;
}
Enemy &Enemy::operator=(Enemy const &src)
{
    this->_hp = src.getHP();
    this->_type = src.getType();
    // std::cout << "Assignation operator called" << std::endl;
    return *this;
}
Enemy::~Enemy()
{
    // std::cout << "An Enemy is destructed." << std::endl;
}
std::string Enemy::getType() const
{
    return this->_type;
}
int Enemy::getHP() const
{
    return this->_hp;
}
void Enemy::takeDamage(int n)
{
    if (n > 0)
    {
        this->_hp -= n;
        // std::cout << "An Enemy takes " << n << " damages" << std::endl;
    }
}