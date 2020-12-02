#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <exception>
# include <iostream>

class Bureaucrat;
class Form
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
private : 
    std::string const   _name;
    bool                _isSigned;
    int const           _gradeSigned;
    int const           _gradeEx;
    Form();

public:
    Form(std::string name, int gradeSigned, int gradeEx);
    Form(Form const &);
    Form &operator=(Form const &);
    ~Form();

    std::string         getName(void) const;
    bool                getIsSigned(void) const;
    int                 getGradeSigned(void) const;
    int                 getGradeEx(void) const;

    void                beSigned(Bureaucrat &);
};
std::ostream &operator<<(std::ostream &o, Form);
#endif