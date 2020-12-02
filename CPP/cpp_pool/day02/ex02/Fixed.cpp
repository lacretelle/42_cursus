#include "Fixed.hpp"

Fixed::Fixed(void) : _raw(0)
{}
Fixed::Fixed(int const n)
{
    this->_raw = roundf((float)n * (1 << Fixed::_nbBits));
}
Fixed::Fixed(float const n) : _raw(n)
{
    this->_raw = roundf(n * (1 << Fixed::_nbBits));
}
Fixed::~Fixed(void)
{}
Fixed::Fixed(Fixed const &src)
{
    *this = src;
}
Fixed &Fixed::operator=(Fixed const &src)
{
    this->_raw = src.getRawBits();
    return *this;
}
bool Fixed::operator>(Fixed const &src)
{
    return this->getRawBits() > src.getRawBits();
}
bool Fixed::operator<(Fixed const &src)
{
    return this->getRawBits() < src.getRawBits();
}
bool Fixed::operator>=(Fixed const &src)
{
    return this->getRawBits() >= src.getRawBits();
}
bool Fixed::operator<=(Fixed const &src)
{
    return this->getRawBits() <= src.getRawBits();
}
bool Fixed::operator==(Fixed const &src)
{
    return this->getRawBits() == src.getRawBits();
}
bool Fixed::operator!=(Fixed const &src)
{
    return this->getRawBits() != src.getRawBits();
}
Fixed Fixed::operator+(Fixed const &src)
{
    Fixed f;
    f.setRawBits(this->getRawBits() + src.getRawBits());
    return f;
}
Fixed Fixed::operator-(Fixed const &src)
{
    Fixed f;
    f.setRawBits(this->getRawBits() - src.getRawBits());
    return f;
}
Fixed Fixed::operator/(Fixed const &src)
{
    Fixed f;
    f.setRawBits((this->getRawBits() - src.getRawBits()) << Fixed::_nbBits);
    return f;
}
Fixed Fixed::operator*(Fixed const &src)
{
    Fixed f;
	f.setRawBits(roundf(this->getRawBits() * src.getRawBits()) / (1 << Fixed::_nbBits));
	return (f);
}
Fixed  Fixed::operator++(void) {
	this->setRawBits(this->getRawBits() + 1);
    return *this;
}
Fixed  Fixed::operator--(void) {
	this->setRawBits(this->getRawBits() - 1);
    return *this;
}
Fixed   Fixed::operator++(int)
{
    Fixed tmp = Fixed (*this);
    this->setRawBits(this->getRawBits() + 1);
    return tmp;
}
Fixed   Fixed::operator--(int)
{
    Fixed tmp = Fixed (*this);
    this->setRawBits(this->getRawBits() - 1);
    return tmp;
}
int Fixed::getRawBits(void) const
{
    return this->_raw;
}
void Fixed::setRawBits(int const raw)
{
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

Fixed const & Fixed::min(Fixed const & rhs1, Fixed const & rhs2) {
	if (rhs1.toFloat() < rhs2.toFloat())
		return (rhs1);
	return (rhs2);
}

Fixed & Fixed::min(Fixed & rhs1, Fixed & rhs2) {
	if (rhs1 < rhs2)
		return (rhs1);
	return (rhs2);
}

Fixed const & Fixed::max(Fixed const & rhs1, Fixed const & rhs2) {
	if (rhs1.toFloat() > rhs2.toFloat())
		return (rhs1);
	return (rhs2);
}

Fixed & Fixed::max(Fixed & rhs1, Fixed & rhs2) {
	if (rhs1 > rhs2)
		return (rhs1);
	return (rhs2);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
    o << rhs.toFloat();
    return o;
}
const int Fixed::_nbBits = 8;