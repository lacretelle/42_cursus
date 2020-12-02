#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP
# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private :
    std::string _target;
    ShrubberyCreationForm();

public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &);
    ~ShrubberyCreationForm();

    std::string getTarget() const;
    void        action();
};
std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm);
#endif