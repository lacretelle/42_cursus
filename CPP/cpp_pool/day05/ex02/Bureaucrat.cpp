#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
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
    return ("This grade is too high !");
}
Bureaucrat::GradeTooLowException::GradeTooLowException() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("This grade is too low !");
}
Bureaucrat::ErrorExplicit::ErrorExplicit(std::string e) : _err(e) {}
Bureaucrat::ErrorExplicit::~ErrorExplicit() throw() {}
const char *Bureaucrat::ErrorExplicit::what() const throw()
{
    if (this->_err == "signed")
        return ("It's impossible to execute this Form because it's not signed !");
    return ("This Bureaucrat has a too low grade to execute it !");
}
std::string const Bureaucrat::getName(void) const
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
void Bureaucrat::signForm(AForm &ref)
{
    if (ref.getGradeSigned() <= this->getGrade())
        std::cout << this->getName() << " signs " << ref.getName() << std::endl;
    else
        std::cout << this->getName() << " cant sign " << ref.getName() << " because grade is too low" << std::endl;
}

void Bureaucrat::executeForm(AForm const &form)
{
    if (form.getIsSigned())
    {
        if (this->getGrade() <= form.getGradeEx())
            std::cout << this->getName() << " executs " << form.getName() << std::endl;
        else
            throw Bureaucrat::ErrorExplicit("");
    }
    else
        throw Bureaucrat::ErrorExplicit("signed");
}