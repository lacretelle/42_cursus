#include <iostream>
#include <string>
#include "read.hpp"
#include "abstractVM.hpp"
#include "exception.hpp"

int main(int argc, char **argv)
{
    Read *r = new Read();
    AbstractVM act;
    if (argc <= 2)
    {
        try
        {
            if (argc == 1)
                r->readInput();
            else
                r->readFile(argv[1]);
            act.dispatcher(r);
        }
        catch (const Exception &e)
        {
            delete r;
            std::cout << e.what() << std::endl;
            return 1;
        }
        catch (const std::exception &e)
        {
            delete r;
            std::cout << e.what() << std::endl;
            return 1;
        }
    }
    else
    {
        std::cout << "usage: ./avm then enter instruction or ./avm FILE" << std::endl;
        return 1;
    }
    return 0;
}