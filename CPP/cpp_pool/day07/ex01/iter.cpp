#include <string>
#include <iostream>

template<typename T>
void    iter(T * arr, size_t size, void (*f)(T&))
{
    size_t i =0;
    while (i < size)
    {
        f(arr[i]);
        i++;
    }
}

template<typename T>
void    f(T & x)
{
    std::cout << "Enter in function f, whith parameter: " << x << std::endl;
}