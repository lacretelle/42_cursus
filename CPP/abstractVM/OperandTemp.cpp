#include "OperandTemp.hpp"
#include "exception.hpp"
#include "OperandFactory.hpp"
#include <cfenv>
#include <string>
#include <cmath>
#include <iostream>

std::string cutZero(std::string s)
{
        size_t count = 0;
        size_t found = s.find(".");
        if (found != std::string::npos)
        {
            size_t i = s.size() - 1;
            while (i > found)
            {
                if (s[i] == '0')
                    count++;
                i--;
            }
        }
        s = s.substr(0, s.size() - count);
    return s;
}

OperandTemp::OperandTemp(eOperandType type, std::string value)
{
    this->_opType = type;
    if (type == Double || type == Float)
    {
        this->_value = cutZero(value);
        if (type == Float)
            this->_precision = 4;
        else
            this->_precision = 5;
    }
    else
    {
        if (type == Int8)
            this->_precision = 1;
        else if (type == Int16)
            this->_precision = 2;
        else
            this->_precision = 3;
        this->_value = value;
    }
}
OperandTemp::OperandTemp(OperandTemp const &src)
{
    *this = src;
}
OperandTemp &OperandTemp::operator=(OperandTemp const &src)
{
    if (this != &src)
    {
        this->_opType = src.getType();
        this->_precision = src.getPrecision();
        this->_value = src.toString();
    }
    return *this;
}
OperandTemp::~OperandTemp() {}
int OperandTemp::getPrecision(void) const
{
    return this->_precision;
}
eOperandType OperandTemp::getType(void) const
{
    return this->_opType;
}

IOperand const *OperandTemp::operator+(IOperand const &rhs) const
{
    OperandFactory opFactory;
    int err = std::fetestexcept(FE_ALL_EXCEPT);
    double tmpNb = std::stod(this->toString());
    double tmpRhs = std::stod(rhs.toString());
    eOperandType resType = this->getPrecision() < rhs.getPrecision() ? rhs.getType() : this->getType();
    tmpNb = tmpNb + tmpRhs;
    if (err & FE_UNDERFLOW)
    {
        throw Exception(UNDERFLOWER, "add", 0);
    }
    if (err & FE_OVERFLOW)
    {
        throw Exception(OVERFLOWER, "add", 0);
    }
    if (this->getPrecision() == 1)
        return (opFactory.createOperand(resType, std::to_string(static_cast<int8_t>(tmpNb))));
    else if (this->getPrecision() == 2)
        return (opFactory.createOperand(resType, std::to_string(static_cast<int16_t>(tmpNb))));
    else if (this->getPrecision() == 3)
        return (opFactory.createOperand(resType, std::to_string(static_cast<int32_t>(tmpNb))));
    else if (this->getPrecision() == 4)
        return (opFactory.createOperand(resType, std::to_string(static_cast<float>(tmpNb))));
    return (opFactory.createOperand(resType, std::to_string(tmpNb)));
}
IOperand const *OperandTemp::operator-(IOperand const &rhs) const
{
    OperandFactory opFactory;
    int err = std::fetestexcept(FE_ALL_EXCEPT);
    double tmpNb = std::stod(this->toString());
    double tmpRhs = std::stod(rhs.toString());
    eOperandType resType = this->getPrecision() < rhs.getPrecision() ? rhs.getType() : this->getType();
    tmpNb = tmpNb - tmpRhs;
    if (err & FE_UNDERFLOW)
    {
        throw Exception(UNDERFLOWER, "sub", 0);
    }
    if (err & FE_OVERFLOW)
    {
        throw Exception(OVERFLOWER, "sub", 0);
    }
    if (this->getPrecision() == 1)
        return (opFactory.createOperand(resType, std::to_string(static_cast<int8_t>(tmpNb))));
    else if (this->getPrecision() == 2)
        return (opFactory.createOperand(resType, std::to_string(static_cast<int16_t>(tmpNb))));
    else if (this->getPrecision() == 3)
        return (opFactory.createOperand(resType, std::to_string(static_cast<int32_t>(tmpNb))));
    else if (this->getPrecision() == 4)
        return (opFactory.createOperand(resType, std::to_string(static_cast<float>(tmpNb))));
    return (opFactory.createOperand(resType, std::to_string(tmpNb)));
}
IOperand const *OperandTemp::operator*(IOperand const &rhs) const
{
    OperandFactory opFactory;
    int err = std::fetestexcept(FE_ALL_EXCEPT);
    double tmpNb = std::stod(this->toString());
    double tmpRhs = std::stod(rhs.toString());
    eOperandType resType = this->getPrecision() < rhs.getPrecision() ? rhs.getType() : this->getType();
    tmpNb = tmpNb * tmpRhs;
    if (err & FE_UNDERFLOW)
    {
        throw Exception(UNDERFLOWER, "mul", 0);
    }
    if (err & FE_OVERFLOW)
    {
        throw Exception(OVERFLOWER, "mul", 0);
    }
    if (this->getPrecision() == 1)
        return (opFactory.createOperand(resType, std::to_string(static_cast<int8_t>(tmpNb))));
    else if (this->getPrecision() == 2)
        return (opFactory.createOperand(resType, std::to_string(static_cast<int16_t>(tmpNb))));
    else if (this->getPrecision() == 3)
        return (opFactory.createOperand(resType, std::to_string(static_cast<int32_t>(tmpNb))));
    else if (this->getPrecision() == 4)
        return (opFactory.createOperand(resType, std::to_string(static_cast<float>(tmpNb))));
    return (opFactory.createOperand(resType, std::to_string(tmpNb)));
}
IOperand const *OperandTemp::operator/(IOperand const &rhs) const
{
    OperandFactory opFactory;
    int err = std::fetestexcept(FE_ALL_EXCEPT);
    double tmpNb = std::stod(this->toString());
    double tmpRhs = std::stod(rhs.toString());
    if (tmpRhs == 0.0)
        throw Exception(BYZERO, "", 0);
    eOperandType resType = this->getPrecision() < rhs.getPrecision() ? rhs.getType() : this->getType();
    tmpNb = tmpNb / tmpRhs;
    if (err & FE_UNDERFLOW)
    {
        throw Exception(UNDERFLOWER, "div", 0);
    }
    if (err & FE_OVERFLOW)
    {
        throw Exception(OVERFLOWER, "div", 0);
    }
    if (this->getPrecision() == 1)
        return (opFactory.createOperand(resType, std::to_string(static_cast<int8_t>(tmpNb))));
    else if (this->getPrecision() == 2)
        return (opFactory.createOperand(resType, std::to_string(static_cast<int16_t>(tmpNb))));
    else if (this->getPrecision() == 3)
        return (opFactory.createOperand(resType, std::to_string(static_cast<int32_t>(tmpNb))));
    else if (this->getPrecision() == 4)
        return (opFactory.createOperand(resType, std::to_string(static_cast<float>(tmpNb))));
    return (opFactory.createOperand(resType, std::to_string(tmpNb)));
}
IOperand const *OperandTemp::operator%(IOperand const &rhs) const
{
    OperandFactory opFactory;
    int err = std::fetestexcept(FE_ALL_EXCEPT);
    double tmpNb = std::stod(this->toString());
    double tmpRhs = std::stod(rhs.toString());
    eOperandType resType = this->getPrecision() < rhs.getPrecision() ? rhs.getType() : this->getType();
    if (tmpRhs == 0.0)
        throw Exception(BYZERO, "", 0);
    tmpNb = std::fmod(tmpNb, tmpRhs);
    if (err & FE_UNDERFLOW)
    {
        throw Exception(UNDERFLOWER, "mod", 0);
    }
    if (err & FE_OVERFLOW)
    {
        throw Exception(OVERFLOWER, "mod", 0);
    }
    if (this->getPrecision() == 1)
        return (opFactory.createOperand(resType, std::to_string(static_cast<int8_t>(tmpNb))));
    else if (this->getPrecision() == 2)
        return (opFactory.createOperand(resType, std::to_string(static_cast<int16_t>(tmpNb))));
    else if (this->getPrecision() == 3)
        return (opFactory.createOperand(resType, std::to_string(static_cast<int32_t>(tmpNb))));
    else if (this->getPrecision() == 4)
        return (opFactory.createOperand(resType, std::to_string(static_cast<float>(tmpNb))));
    return (opFactory.createOperand(resType, std::to_string(tmpNb)));
}
std::string const &OperandTemp::toString(void) const
{
    return this->_value;
}