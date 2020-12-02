#include <iostream>
#include "token.hpp"

Token::Token(){}
Token::Token(size_t nbLine, eToken type, std::string val, std::string nb) : _line(nbLine), _type(type), _value(val), _nb(nb) {}
Token::Token(Token const &src) { *this = src; }
Token &Token::operator=(Token const &src)
{
    if (this != &src)
    {
        this->_line = src.getTokenLine();
        this->_type = src.getTokenType();
        this->_value = src.getTokenValue();
        this->_nb = src.getTokenNb();
    }
    return *this;
}
Token::~Token() {}
eToken Token::getTokenType() const
{
    return this->_type;
}
std::string Token::getTokenValue() const
{
    return this->_value;
}
size_t Token::getTokenLine() const
{
    return this->_line;
}
std::string Token::getTokenNb() const
{
    return this->_nb;
}