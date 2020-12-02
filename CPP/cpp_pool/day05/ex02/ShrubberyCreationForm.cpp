#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
    *this = src;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
    if (this != &src)
{
        AForm::operator=(src);
        this->_target = src.getTarget();
}
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

void        ShrubberyCreationForm::action()
{
    std::cout << "coucou in ShrubberyCreationForm" << std::endl;
//     Crée un fichier nommé <target>_shrubbery, et dessines des arbres en ASCII
// dedans, dans le dossier courant.
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm src)
{
    o << "ShrubberyCreationForm " << src.getName() << ", signed:" << src.getIsSigned() << ", which grade is " << src.getGradeSigned() << " to signed it and grade is " << src.getGradeEx() << " to excute it.";
    return o;
}
