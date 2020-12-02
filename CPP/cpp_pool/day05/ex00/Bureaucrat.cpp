#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    if (grade < 1)
        throw(Bureaucrat::GradeTooLowException());
    if (grade > 150)
        throw(Bureaucrat::GradeTooHighException());
    this->_grade = grade;
}
Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName())
{
    *this = src;
}
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
    if (this != &src)
    {
        this->_grade = src.getGrade();
        // this->_name = src.getName();
    }
    return *this;
}
Bureaucrat::~Bureaucrat() {}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("This grade is too high, enter a grade between 1 and 150 !");
}
Bureaucrat::GradeTooLowException::GradeTooLowException() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("This grade is too low, enter a grade between 1 and 150 !");
}

std::string  Bureaucrat::getName(void) const
{
    return this->_name;
}
int Bureaucrat::getGrade(void) const
{
    return this->_grade;
}
void Bureaucrat::incrementGrade()
{
    if (this->getGrade() > 1)
        this->_grade -= 1;
}
void Bureaucrat::decrementGrade()
{
    if (this->getGrade() < 150)
        this->_grade += 1;
}
std::ostream &operator<<(std::ostream &o, Bureaucrat src)
{
    o << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
    return o;
}
