#include "span.hpp"

Span::Span() : _N(0) {}
Span::Span(unsigned int n) : _N(n) {}
Span::Span(Span const & src)
{
    *this = src;
}
Span & Span::operator=(Span const & src)
{
    this->_N = src.getN();
    return *this;
}
Span::~Span() {}
unsigned int    Span::getN() const
{
    return this->_N;
}