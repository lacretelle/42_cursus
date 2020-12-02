#ifndef OPERAND_TEMP_HPP
# define OPERAND_TEMP_HPP
# include "IOperand.hpp"
# include "eOperandType.hpp"

class OperandTemp : public IOperand
{
public:
    OperandTemp(eOperandType, std::string);
    OperandTemp(OperandTemp const &);
    OperandTemp & operator=(OperandTemp const &);
    ~OperandTemp();

    int getPrecision(void) const;
    eOperandType getType(void) const;
    IOperand const *operator+(IOperand const &rhs) const;
    IOperand const *operator-(IOperand const &rhs) const;
    IOperand const *operator*(IOperand const &rhs) const;
    IOperand const *operator/(IOperand const &rhs) const;
    IOperand const *operator%(IOperand const &rhs) const;
    std::string const & toString(void) const;

private:
    int             _precision;
    eOperandType    _opType;
    std::string     _value;
};

#endif