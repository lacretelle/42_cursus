#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm() {}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target){}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
    *this = src;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
    if (this != &src)
{
        AForm::operator=(src);
        this->_target = src.getTarget();
}
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const
{
    return this->_target;
}

void        RobotomyRequestForm::action()
{
    std::cout << "* Make drill noises *" << std::endl;
    std::cout << this->getTarget() << " has robotomized !" << std::endl;
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm src)
{
    o << "RobotomyRequestForm " << src.getName() << ", signed:" << src.getIsSigned() << ", which grade is " << src.getGradeSigned() << " to signed it and grade is " << src.getGradeEx() << " to excute it.";
    return o;
}
