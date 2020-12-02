#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat test2 = Bureaucrat("jb", -1);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat test3 = Bureaucrat("john", 178);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat test1 = Bureaucrat("jim", 2);
        Bureaucrat test4 = Bureaucrat("lilou", 89);
        std::cout << test1 << std::endl;
        test1.incrementGrade();
        test1.incrementGrade();
        std::cout << test1 << std::endl;
        test1.incrementGrade();
        std::cout << test1 << std::endl;
        test1.decrementGrade();
        test1.decrementGrade();
        std::cout << test1 << std::endl;
        test1.incrementGrade();
        std::cout << test1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
try
    {
        Bureaucrat test1 = Bureaucrat("maduf", 2);
        Bureaucrat test4 = Bureaucrat("cracotte", 89);
        test4 = test1;
        std::cout << test4 << std::endl;
        test4.incrementGrade();
        test4.incrementGrade();
        std::cout << test4 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}