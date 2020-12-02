#include "Fixed.hpp"

Fixed::Fixed(void) : _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(int const n)
{
    this->_raw = roundf((float)n * (1 << Fixed::_nbBits));
}
Fixed::Fixed(float const n) : _raw(n)
{
    this->_raw = roundf(n * (1 << Fixed::_nbBits));
}
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(Fixed const & src)
{
    *this = src;
}
Fixed & Fixed::operator=(Fixed const & src)
{
    this->_raw = src.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_raw = raw;
}
float Fixed::toFloat(void) const
{
    return ((float)this->getRawBits() / (1 << Fixed::_nbBits));
}
int Fixed::toInt(void) const
{
    return (this->getRawBits() / (1 << Fixed::_nbBits));
}
std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
const int	Fixed::_nbBits = 8;