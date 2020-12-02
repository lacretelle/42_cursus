#include "OperandFactory.hpp"
#include "OperandTemp.hpp"
#include <map>
#include <iostream>

typedef IOperand const *(OperandFactory::*funcFactory)(std::string const &) const;
OperandFactory::OperandFactory() {}
OperandFactory::OperandFactory(OperandFactory const &src)
{
    *this = src;
}
OperandFactory &OperandFactory::operator=(OperandFactory const &src)
{
    (void)src;
    return *this;
}
OperandFactory::~OperandFactory() {}
IOperand const *OperandFactory::createOperand(eOperandType type, std::string const &value) const
{
    std::map<eOperandType, funcFactory> fcreate;
    fcreate.insert(std::pair<eOperandType, funcFactory>(Int8, &OperandFactory::createInt8));
    fcreate.insert(std::pair<eOperandType, funcFactory>(Int16, &OperandFactory::createInt16));
    fcreate.insert(std::pair<eOperandType, funcFactory>(Int32, &OperandFactory::createInt32));
    fcreate.insert(std::pair<eOperandType, funcFactory>(Float, &OperandFactory::createFloat));
    fcreate.insert(std::pair<eOperandType, funcFactory>(Double, &OperandFactory::createDouble));
    funcFactory search = fcreate[type];
    return (this->*search)(value);
}

IOperand const *OperandFactory::createInt8(std::string const &value) const
{
    OperandTemp *newOp = new OperandTemp(Int8, value);
    return reinterpret_cast<IOperand *>(newOp);
}
IOperand const *OperandFactory::createInt16(std::string const &value) const
{
    OperandTemp *newOp = new OperandTemp(Int16, value);
    return reinterpret_cast<IOperand *>(newOp);
}
IOperand const *OperandFactory::createInt32(std::string const &value) const
{
    OperandTemp *newOp = new OperandTemp(Int32, value);
    return reinterpret_cast<IOperand *>(newOp);
}
IOperand const *OperandFactory::createFloat(std::string const &value) const
{
    OperandTemp *newOp = new OperandTemp(Float, value);
    return reinterpret_cast<IOperand *>(newOp);
}
IOperand const *OperandFactory::createDouble(std::string const &value) const
{
    OperandTemp *newOp = new OperandTemp(Double, value);
    return reinterpret_cast<IOperand *>(newOp);
}