#include "exception.hpp"

Exception::Exception(eTypeException ex, std::string input, size_t numLine) : _ex(ex), _input(input), _numLine(numLine) {}
Exception::Exception(Exception const &src) { *this = src; }
Exception &Exception::operator=(Exception const &src)
{
    (void)src;
    return *this;
}
Exception::~Exception() throw() {}

eTypeException Exception::getException() const
{
    return this->_ex;
}
std::string Exception::getInput() const
{
    return this->_input;
}
size_t Exception::getNumLine() const
{
    return this->_numLine;
}

const char *Exception::what() const throw()
{
    std::ostringstream line;
    line << "Line: " << this->getNumLine() + 1 << ": ";
    if (this->getException() == OVERFLOWLOW)
        line
            << "This input " << this->getInput() << ", it's lower than the min";
    else if (this->getException() == OVERFLOWHIGH)
        line
            << "This input " << this->getInput() << ", it's higher than the max";
    else if (this->getException() == BADINSTRUCTION)
        line
            << "It's impossible to " << this->getInput() << ".";
    else if (this->getException() == INVALIDINPUT)
        line
            << "Enter valid instruction.";
    else if (this->getException() == OPIMPOSSIBLE)
        line
            << "This operation is impossible because " << this->getInput() << ".";
    else if (this->getException() == ACTIMPOSSIBLE)
        line
            << "This action is impossible because " << this->getInput() << ".";
    else if (this->getException() == NOTNUMBER)
        line
            << "This input " << this->getInput() << " can't be executed.";
    else if (this->getException() == OPENIMPOSSIBLE)
        line
            << "It's impossible to open this file " << this->getInput() << ".";
    else if (this->getException() == NOTHINGTODO)
        line
            << "There isn't any instruction.";
    else if (this->getException() == UNDERFLOWER)
        line
            << "The result of this operation " << this->getInput() << "  was subnormal with a loss of precision";
    else if (this->getException() == OVERFLOWER)
        line
            << "The result of this operation " << this->getInput() << "  was too large to be representable";
    else if (this->getException() == BYZERO)
        line
            << "Division or Modulo by zero is impossible.";
    else if (this->getException() == ERRORTYPE)
        line << "Those types aren't equals.";
    else if (this->getException() == VALUENOTSAME)
        line
            << "Those values aren't equals";
    else if (this->getException() == NOEXIT)
        line
            << "There is no instruction exit at the end of this program.";
    else if (this->getException() == NOTINT8)
        line
            << "The value at the top of the stack is not an 8-bit integer.";
    std::string tmp = line.str();
    char *res = new char[tmp.size() + 1];
    std::copy(tmp.begin(), tmp.end(), res);
    res[tmp.size()] = '\0';
    return res;
}