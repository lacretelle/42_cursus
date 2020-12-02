#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm() {}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target){}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
    *this = src;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
    if (this != &src)
{
        AForm::operator=(src);
        this->_target = src.getTarget();
}
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const
{
    return this->_target;
}

void        PresidentialPardonForm::action()
{
    std::cout << this->getTarget() << " has been forgiven by Zafod Beeblebrox !" << std::endl;
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm src)
{
    o << "PresidentialPardonForm " << src.getName() << ", signed:" << src.getIsSigned() << ", which grade is " << src.getGradeSigned() << " to signed it and grade is " << src.getGradeEx() << " to excute it.";
    return o;
}
