#include "Pony.hpp"

Pony::Pony(std::string name, std::string color, std::string sign) : _name(name), _color(color), _sign(sign)
{
    std::cout << "Pony " << this->_name << " is born, these characteristics are color: " << this->_color << " and sign: " << this->_sign << std::endl;
}
Pony::~Pony()
{
    std::cout << "Pony " << this->_name << " died" << std::endl;
}

std::string Pony::getName(void)
{
    return this->_name;
}
std::string Pony::getColor(void)
{
    return this->_color;
}
std::string Pony::getSign(void)
{
    return this->_sign;
}
void Pony::setColor(std::string color)
{
    this->_color = color;
}
void Pony::setSign(std::string sign)
{
    this->_sign = sign;
}
