#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP
# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private :
    std::string _target;
    PresidentialPardonForm();

public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const &);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &);
    ~PresidentialPardonForm();

    std::string getTarget() const;
    void        action();
};
std::ostream &operator<<(std::ostream &o, PresidentialPardonForm);
#endif