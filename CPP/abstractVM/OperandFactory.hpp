#ifndef OPERAND_FACTORY_HPP
# define OPERAND_FACTORY_HPP
# include "IOperand.hpp"
# include "eOperandType.hpp"

class OperandFactory
{
public:
    OperandFactory();
    OperandFactory(OperandFactory const &);
    OperandFactory & operator=(OperandFactory const &);
    ~OperandFactory();
    IOperand const *createOperand(eOperandType type, std::string const &value) const;

private:
    IOperand const *createInt8(std::string const &value) const;
    IOperand const *createInt16(std::string const &value) const;
    IOperand const *createInt32(std::string const &value) const;
    IOperand const *createFloat(std::string const &value) const;
    IOperand const *createDouble(std::string const &value) const;
};

// In order to choose the right member function for the creation of the new IOperand,
// you MUST create and use an array (here, a vector shows little interest) of pointers on
// member functions with enum values as index.
#endif