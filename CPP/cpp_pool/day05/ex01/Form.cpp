#include "Form.hpp"

Form::Form() : _name(""), _gradeEx(150), _gradeSigned(150) {}
Form::Form(std::string name, int gradeSigned, int gradeEx) : _name(name), _isSigned(false), _gradeEx(gradeSigned), _gradeSigned(gradeEx)
{
    if (gradeSigned < 1 || gradeEx < 1)
        throw(Form::GradeTooLowException());
    if (gradeSigned > 150 || gradeEx > 150)
        throw(Form::GradeTooHighException());
}
Form::Form(Form const &src) : _name(src.getName()), _gradeEx(src.getGradeEx()), _gradeSigned(src.getGradeSigned())
{
    *this = src;
}
Form &Form::operator=(Form const &src)
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
Form::~Form() {}

Form::GradeTooHighException::GradeTooHighException() {}
Form::GradeTooHighException::~GradeTooHighException() throw() {}
const char *Form::GradeTooHighException::what() const throw()
{
    return ("This grade is too high !");
}
Form::GradeTooLowException::GradeTooLowException() {}
Form::GradeTooLowException::~GradeTooLowException() throw() {}
const char *Form::GradeTooLowException::what() const throw()
{
    return ("This grade is too low !");
}

std::string Form::getName(void) const
{
    return this->_name;
}
bool Form::getIsSigned(void) const
{
    return this->_isSigned;
}
int Form::getGradeSigned(void) const
{
    return this->_gradeSigned;
}
int Form::getGradeEx(void) const
{
    return this->_gradeEx;
}
void Form::beSigned(Bureaucrat &ref)
{
    if (ref.getGrade() <= this->getGradeSigned())
    {
        std::cout << "Bureaucrat " << ref.getName() << "has signed this Form" << std::endl;
        this->_isSigned = true;
    }
    else
        throw Form::GradeTooLowException();
}
std::ostream &operator<<(std::ostream &o, Form src)
{
    o << "Form " << src.getName() << ", signed:" << src.getIsSigned() << ", which grade is " << src.getGradeSigned() << " to signed it and grade is " << src.getGradeEx() << " to excute it.";
    return o;
}
