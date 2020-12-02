#include "AForm.hpp"

AForm::AForm() : _name(""), _isSigned(false), _gradeSigned(150), _gradeEx(150) {}
AForm::AForm(std::string name, int gradeSigned, int gradeEx) : _name(name), _isSigned(false), _gradeSigned(gradeSigned), _gradeEx(gradeEx)
{
    if (gradeSigned < 1 || gradeEx < 1)
        throw(AForm::GradeTooLowException());
    if (gradeSigned > 150 || gradeEx > 150)
        throw(AForm::GradeTooHighException());
}
AForm::AForm(AForm const &src) : _name(src.getName()), _gradeSigned(src.getGradeSigned()), _gradeEx(src.getGradeEx())
{
    *this = src;
}
AForm &AForm::operator=(AForm const &src)
{
    if (this != &src)
    {
        this->_isSigned = src.getIsSigned();
        // this->_gradeSigned = src.getGradeSigned();
        // this->_gradeEx = src.getGradeSigned();
        // this->_name = src.getName();
    }
    return *this;
}
AForm::~AForm() {}

AForm::GradeTooHighException::GradeTooHighException() {}
AForm::GradeTooHighException::~GradeTooHighException() throw() {}
const char *AForm::GradeTooHighException::what() const throw()
{
    return ("This grade is too high !");
}
AForm::GradeTooLowException::GradeTooLowException() {}
AForm::GradeTooLowException::~GradeTooLowException() throw() {}
const char *AForm::GradeTooLowException::what() const throw()
{
    return ("This grade is too low !");
}
AForm::FormNotSigned::FormNotSigned() {}
AForm::FormNotSigned::~FormNotSigned() throw() {}
const char *AForm::FormNotSigned::what() const throw()
{
    return ("This Form isn't signed !");
}
std::string const AForm::getName(void) const
{
    return this->_name;
}
bool AForm::getIsSigned(void) const
{
    return this->_isSigned;
}
int AForm::getGradeSigned(void) const
{
    return this->_gradeSigned;
}
int AForm::getGradeEx(void) const
{
    return this->_gradeEx;
}
void AForm::beSigned(Bureaucrat &ref)
{
    if (ref.getGrade() <= this->getGradeSigned())
    {
        std::cout << "Bureaucrat " << ref.getName() << "has signed this AForm" << std::endl;
        this->_isSigned = true;
    }
    else
        throw AForm::GradeTooLowException();
}
void AForm::execute(Bureaucrat const & executor)
{
    if (this->getIsSigned())
    {
        if (executor.getGrade() <= this->getGradeEx())
            this->action();
        else
            throw AForm::GradeTooLowException();
    } else
        throw AForm::FormNotSigned();
}