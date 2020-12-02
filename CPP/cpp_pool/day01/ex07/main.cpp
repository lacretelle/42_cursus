#include <fstream>
#include <iostream>
#include <string>
#include "ReplaceFile.hpp"

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        std::string param1 = argv[1];
        std::string param2 = argv[2];
        std::string param3 = argv[3];
        if (param1.size() > 0 && param2.size() > 0 && param3.size() > 0)
        {
            ReplaceFile res;
            res.setNewFile(param1, param2, param3);
            std::ifstream file(res.getNameFile());
            if (file)
            {
                std::cout << "File  " << param1 << " replace is ready to read." << std::endl;
                return 0;
            }
        }
        else
        {
            std::cout << "An error occured" << std::endl;
        }
    }
    else
    {
        std::cout << "Please enter a filename and two strings." << std::endl;
    }
    return 1;
}