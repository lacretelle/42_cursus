#include "Array.hpp"

// int main()
// {
//     try
//     {
//         Array<int> test = Array<int>();
//         Array<int> test1 = Array<int>(8);
//         Array<std::string> test3 = Array<std::string>(8);
//         Array<std::string> test4 = Array<std::string>(20);

//         test = test1;
//         std::cout << test.size() << std::endl;
//         test3 = test4;
//         std::cout << test3.size() << std::endl;
//         test[0] = 42;
//         test[7] = 8;
//         std::cout << test[0] << std::endl;
//         std::cout << test[7] << std::endl;
//         std::cout << test[9] << std::endl;
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     return 0;
// }

int main()
{
    try
    {
        //Array<char> test;
        Array<int> intTab = Array<int>(5);
        Array<int> intTab2 = Array<int>(5);
        Array<int> intTab3 = intTab2;
        //ICI A VOIR	std::cout << test << std::endl;
        std::cout << intTab[0] << std::endl;
        intTab[2] = 42;
        std::cout << intTab[2] << std::endl;
        intTab2 = intTab;
        std::cout << intTab2[2] << std::endl;
        intTab[0] = 470;
        std::cout << intTab[0] << std::endl;
        std::cout << intTab2[0] << std::endl;
        intTab[457] = 8;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}