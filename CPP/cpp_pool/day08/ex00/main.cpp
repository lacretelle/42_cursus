#include "easyfind.hpp"
#include <iostream>

int main()
{
    int res = -1;
    int const arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vec0 (arr, arr + n);

    int const arr1[] = {1, 4, 3, 4, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    std::vector<int> vec1 (arr1, arr1 + n1);
    res = easyfind(vec0, 4);
    if (res > -1)
        std::cout << "The first occurence is: " << res << std::endl;
    else
        std::cout << "An error occured !"<< std::endl;
    res = easyfind(vec0, 0);
    if (res > -1)
        std::cout << "The first occurence is: " << res << std::endl;
    else
        std::cout << "An error occured !"<< std::endl;
    res = easyfind(vec1, 4);
    if (res > -1)
        std::cout << "The first occurence is: " << res << std::endl;
    else
        std::cout << "An error occured !"<< std::endl;
    res = easyfind(vec1, 3);
    if (res > -1)
        std::cout << "The first occurence is: " << res << std::endl;
    else
        std::cout << "An error occured !"<< std::endl;
    return 0;
}