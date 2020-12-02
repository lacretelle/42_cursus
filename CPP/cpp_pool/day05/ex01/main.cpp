#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat jim = Bureaucrat("jim", 6);
        Form cerfa1 = Form("cerfa_uno", 2, 189);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat jim = Bureaucrat("jim", 6);
        Form cerfa1 = Form("cerfa_uno", 0, 6);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat jim = Bureaucrat("jim", 6);
        Form cerfa1 = Form("cerfa_uno", -1, 6);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat jim = Bureaucrat("jim", 6);
        Form cerfa1 = Form("cerfa_uno", 290, 6);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat jim = Bureaucrat("jim", 6);
        Bureaucrat frank = Bureaucrat("frank", 98);
        Form cerfa1 = Form("cerfa_uno", 7, 9);
        Form cerfa3 = Form("cerfa_uno", 2, 1);

        std::cout << jim << std::endl;
        std::cout << frank << std::endl;
        cerfa1.beSigned(jim);
        jim.signForm(cerfa1);
        cerfa3.beSigned(jim);
        jim.signForm(cerfa3);
        cerfa1.beSigned(frank);
        frank.signForm(cerfa1);

    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
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