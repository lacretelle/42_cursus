#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include "Form.hpp"
# include <iostream>
# include <exception>

class Form;
class Bureaucrat
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
    int                 _grade; // 1 a 150
    Bureaucrat();

public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &);
    Bureaucrat &operator=(Bureaucrat const &);
    ~Bureaucrat();

    std::string         getName(void) const;
    int                 getGrade(void) const;
    void                incrementGrade(void);
    void                decrementGrade(void);
    void                signForm(Form&);
};
std::ostream &operator<<(std::ostream &o, Bureaucrat);
#endif