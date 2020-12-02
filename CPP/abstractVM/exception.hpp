#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP
# include <exception>
# include <string>
# include <sstream>

enum eTypeException
{
    OVERFLOWLOW, OVERFLOWHIGH, BADINSTRUCTION, INVALIDINPUT, OPIMPOSSIBLE, ACTIMPOSSIBLE, NOTNUMBER, OPENIMPOSSIBLE, NOTHINGTODO, UNDERFLOWER, OVERFLOWER, BYZERO, ERRORTYPE, VALUENOTSAME, NOEXIT
};

class Exception : public std::exception
{
private:
    eTypeException  _ex;
    std::string     _input;
    size_t          _numLine;
public:
    Exception(eTypeException ex, std::string input, size_t numLine);
    Exception(Exception const & src);
    Exception &operator=(Exception const & src);
    ~Exception() throw();

    eTypeException  getException() const;
    std::string     getInput() const;
    size_t          getNumLine() const;
    const char * what () const throw ();
};
#endif