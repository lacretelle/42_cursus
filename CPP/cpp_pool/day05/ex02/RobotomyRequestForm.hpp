#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP
# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private :
    std::string _target;
    RobotomyRequestForm();

public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const &);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &);
    ~RobotomyRequestForm();

    std::string getTarget() const;
    void        action();
};
std::ostream &operator<<(std::ostream &o, RobotomyRequestForm);
#endif