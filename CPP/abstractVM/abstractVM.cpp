#include "abstractVM.hpp"
#include "parser.hpp"
#include "OperandFactory.hpp"
#include <iostream>
#include <map>

AbstractVM::AbstractVM() {}
AbstractVM::AbstractVM(AbstractVM const &src) { *this = src; }
AbstractVM &AbstractVM::operator=(AbstractVM const &src)
{
    if (this != &src)
        (void)src;
    return *this;
}
AbstractVM::~AbstractVM()
{
    if (this->stackVM.size() > 0)
    {
        for (StackVM<const IOperand *>::iterator it = this->stackVM.begin(); it != this->stackVM.end(); it++)
        {
            delete *it;
        }
        this->stackVM.clear();
    }
}
eOperandType convertTokentosOperandType(std::string t)
{
    eOperandType e = Double;
    if (t == "int8")
        e = Int8;
    else if (t == "int16")
        e = Int16;
    else if (t == "int32")
        e = Int32;
    else if (t == "float")
        e = Float;
    return e;
}
/*
* ALL OPERATIONS AND ACTION WE CAN DO
*/
// OPERATIONS
void AbstractVM::addVM()
{
    // get two first elements and pop them
    const IOperand *first = this->stackVM.top();
    this->stackVM.pop();
    const IOperand *second = this->stackVM.top();
    this->stackVM.pop();
    this->stackVM.push(*first + *second);
    // delete this two operands
    delete first;
    delete second;
}
void AbstractVM::subVM()
{
    const IOperand *first = this->stackVM.top();
    this->stackVM.pop();
    const IOperand *second = this->stackVM.top();
    this->stackVM.pop();
    this->stackVM.push(*first - *second);
    // delete this two operands
    delete first;
    delete second;
}
void AbstractVM::mulVM()
{
    const IOperand *first = this->stackVM.top();
    this->stackVM.pop();
    const IOperand *second = this->stackVM.top();
    this->stackVM.pop();
    this->stackVM.push(*first * *second);
    // delete this two operands
    delete first;
    delete second;
}
void AbstractVM::divVM()
{
    const IOperand *first = this->stackVM.top();
    this->stackVM.pop();
    const IOperand *second = this->stackVM.top();
    this->stackVM.pop();
    this->stackVM.push(*first / *second);
    // delete this two operands
    delete first;
    delete second;
}
void AbstractVM::modVM()
{
    const IOperand *first = this->stackVM.top();
    this->stackVM.pop();
    const IOperand *second = this->stackVM.top();
    this->stackVM.pop();
    this->stackVM.push(*first % *second);
    // delete this two operands
    delete first;
    delete second;
}
// ASSERT OR PUSH
void AbstractVM::pushVM(Token *t)
{
    OperandFactory opFac;
    const IOperand *newOne = opFac.createOperand(convertTokentosOperandType(t->getTokenValue()), t->getTokenNb());
    this->stackVM.push(newOne);
}
void AbstractVM::assertVM(Token *t)
{
    // get eOperandType of token and compare
    eOperandType e = convertTokentosOperandType(t->getTokenValue());
    const IOperand *currentTop = this->stackVM.top();
    if (e == currentTop->getType())
    {
        if (t->getTokenNb().compare(currentTop->toString()) != 0)
            throw Exception(ERRORTYPE,"", t->getTokenLine());
    } else
    {
        throw Exception(VALUENOTSAME,"", t->getTokenLine());
    }
}
// ACTIONS
void AbstractVM::popVM()
{
    const IOperand *currentTop = this->stackVM.top();
    this->stackVM.pop();
    delete currentTop;
}
void AbstractVM::dumpVM()
{
    StackVM<const IOperand *> tmp = StackVM<const IOperand *>(stackVM);
    while (!(tmp.empty()))
    {
        std::cout << tmp.top()->toString() << std::endl;
        tmp.pop();
    }
}
void AbstractVM::printVM()
{
    // look if this->stackVM.top() is Int8 type
    // throw EXCEPTION if not
    // AND ==???? PAS COMPRIS
    std::cout << "enter here in printVM " << std::endl;
}

/*
* EXECUTE OPERATION SO FACTORY ETC 
*/
void AbstractVM::execute(Token *t, std::string exec)
{
    typedef void (AbstractVM::*exFunc)();
    std::map<std::string, exFunc> m;
    m.insert(std::pair<std::string, exFunc>("add", &AbstractVM::addVM));
    m.insert(std::pair<std::string, exFunc>("sub", &AbstractVM::subVM));
    m.insert(std::pair<std::string, exFunc>("mul", &AbstractVM::mulVM));
    m.insert(std::pair<std::string, exFunc>("div", &AbstractVM::divVM));
    m.insert(std::pair<std::string, exFunc>("mod", &AbstractVM::modVM));
    m.insert(std::pair<std::string, exFunc>("pop", &AbstractVM::popVM));
    m.insert(std::pair<std::string, exFunc>("dump", &AbstractVM::dumpVM));
    m.insert(std::pair<std::string, exFunc>("print", &AbstractVM::printVM));

    typedef void (AbstractVM::*pushOrAssert)(Token * t);
    std::map<std::string, pushOrAssert> p;
    p.insert(std::pair<std::string, pushOrAssert>("push", &AbstractVM::pushVM));
    p.insert(std::pair<std::string, pushOrAssert>("assert", &AbstractVM::assertVM));
    if (exec.size() > 0)
        (this->*(p[exec]))(t);
    else
        (this->*(m[t->getTokenValue()]))();
}

/*
* 1- SEND TO PARSER
* 2- IF RETURN OK => EXECUTE
*/
void AbstractVM::dispatcher(Read *r)
{
    Parser parse;
    if (!(r->tokens.empty()))
    {
        parse.countInstructionByLine(r->tokens);
        for (size_t i = 0; i < r->tokens.size(); i++)
        {
            parse.checkAll(r->tokens[i], this->stackVM.size());
            std::string exec = "";
            if (r->tokens[i]->getTokenType() == NUMBER)
                exec = r->tokens[i - 1]->getTokenValue();
            if (r->tokens[i]->getTokenType() != ASSERTORPUSH && r->tokens[i]->getTokenType() != EXIT)
                execute(r->tokens[i], exec);
            if (i == r->tokens.size() - 1 && r->tokens[i]->getTokenType() != EXIT)
                throw Exception(NOEXIT, "", r->tokens[i]->getTokenLine());
        }
    }
    else
    {
        throw Exception(NOTHINGTODO, "", 0);
    }
}
