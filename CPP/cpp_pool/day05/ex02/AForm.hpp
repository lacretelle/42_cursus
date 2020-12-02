#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"
# include <exception>
# include <iostream>

class Bureaucrat;
class AForm
{
    class GradeTooHighException : public std::exception
    {
        public:
            GradeTooHighException();
            ~GradeTooHighException() throw();
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            GradeTooLowException();
            ~GradeTooLowException() throw();
            const char* what() const throw();
    };
    class FormNotSigned : public std::exception
    {
        public:
            FormNotSigned();
            ~FormNotSigned() throw();
            const char* what() const throw();
    };
private : 
    std::string const   _name;
    bool                _isSigned;
    int const           _gradeSigned;
    int const           _gradeEx;

public:
    AForm();
    AForm(std::string name, int gradeSigned, int gradeEx);
    AForm(AForm const &);
    AForm &operator=(AForm const &);
    virtual ~AForm();

    virtual std::string const   getName(void) const;
    virtual bool                getIsSigned(void) const;
    virtual int           getGradeSigned(void) const;
    virtual int           getGradeEx(void) const;

    virtual void                beSigned(Bureaucrat &);

    virtual void                execute(Bureaucrat const & executor);
    virtual void                action() = 0;
};
#endif