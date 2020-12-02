#include <iostream>
#include <cctype>
#include <cstdlib>
#include "convert.cpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string str;
        double d;
        bool isImpossible = false;
        str = argv[1];

        // exception display impossible or nan or nanf
        if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("nanf") == 0 || str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("nan") == 0)
            isImpossible = true;
        if (str.size() == 1)
        {
            d = atof(argv[1]);
            for (size_t i = 0; i < str.size(); i++)
            {
                if (isdigit(str[i]))
                    convertInt(d, isImpossible);
            }
            if (isalpha(str[0]))
                convertChar(d, isImpossible);
        }
        int isInt = 0;
        for (size_t i = 0; i < str.size(); i++)
        {
            if (i == 0 && str[0] == '-')
                i++;
            if (i == str.size() - 1 && str[i] == 'f')
            {
                d = atof(argv[1]);
                convertFloat(d, isImpossible);
            }
            if (str[i] == '.')
            {
                isInt = 1;
                i++;
            }
            if (!isdigit(str[i]))
            {
                return 1;
            }
        }
        d = atof(argv[1]);
        isInt == 0 ? convertInt(d, isImpossible) : convertDouble(d, isImpossible);
    }
    return 0;
}