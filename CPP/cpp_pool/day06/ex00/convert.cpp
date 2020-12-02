#include <iostream>
// #include <climits>
//numeric_limits
// std::numeric_limits<int>::min()
char static MIN_CHAR = std::numeric_limits<char>::min();
char static MAX_CHAR = std::numeric_limits<char>::max();
int static MIN_INT = std::numeric_limits<int>::min();
int static MAX_INT = std::numeric_limits<int>::max();
float static MIN_FLOAT = std::numeric_limits<float>::min();
float static MAX_FLOAT = std::numeric_limits<float>::max();
double static MIN_DOUBLE = std::numeric_limits<double>::min();
double static MAX_DOUBLE = std::numeric_limits<double>::max();

void    convertChar(double d, bool isImpossible)
{
    if (isImpossible)
    {
        displayInt("impossible");
        displayFloat(static_cast<float>(d));
        displayDouble(static_cast<double>(d));
    }
    displayInt(static_cast<int>(d));
    displayFloat(static_cast<float>(d));
    displayDouble(static_cast<double>(d));
}
void    convertInt(double d, bool isImpossible)
{
    int i = static_cast<int>(str);
    displayChar();
    displayFloat();
    displayDouble();
}
void    convertFloat(double d, bool isImpossible)
{
    displayChar();
    displayInt();
    displayDouble();
}
void    convertDouble(double d, bool isImpossible)
{
    displayChar();
    displayInt();
    displayFloat();
}
void    displayChar(char c)
{
std::cout << "char: " << c << std::endl;
}
void    displayInt(int i)
{
std::cout << "int: " << i << std::endl;

}
void    displayFloat(float f)
{
std::cout << "float: " << f << std::endl;

}
void    displayDouble(double d)
{
std::cout << "double: " << d << std::endl;

}