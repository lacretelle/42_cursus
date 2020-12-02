#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat jim = Bureaucrat("jim", 6);
        Bureaucrat tod = Bureaucrat("tod", 140);
        ShrubberyCreationForm cerfa1 = ShrubberyCreationForm("tim");
        tod.signForm(cerfa1);
        tod.executeForm(cerfa1);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
//     try
//     {
//         Bureaucrat jim = Bureaucrat("jim", 6);
//         Bureaucrat frank = Bureaucrat("frank", 98);
//         AForm cerfa1 = AForm("cerfa_uno", 7, 9);
//         AForm cerfa3 = AForm("cerfa_uno", 2, 1);

//         std::cout << jim << std::endl;
//         std::cout << frank << std::endl;
//         cerfa1.beSigned(jim);
//         jim.signAForm(cerfa1);
//         cerfa3.beSigned(jim);
//         jim.signAForm(cerfa3);
//         cerfa1.beSigned(frank);
//         frank.signAForm(cerfa1);

//     }
//     catch (const std::exception &e)
//     {
//         std::cout << e.what() << std::endl;
//     }
// try
//     {
//         Bureaucrat test1 = Bureaucrat("maduf", 2);
//         Bureaucrat test4 = Bureaucrat("cracotte", 89);
//         test4 = test1;
//         std::cout << test4 << std::endl;
//         test4.incrementGrade();
//         test4.incrementGrade();
//         std::cout << test4 << std::endl;
//     }
//     catch (const std::exception &e)
//     {
//         std::cout << e.what() << std::endl;
//     }
    return 0;
}