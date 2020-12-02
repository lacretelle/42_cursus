#include "Fixed.hpp"

Fixed::Fixed(void) : _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(Fixed const &src)
{
    *this = src;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &src)
{
    std::cout << "Assignation operator called" << std::endl;
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
    this->_raw = raw;
}

const int	Fixed::_nbBits = 8;