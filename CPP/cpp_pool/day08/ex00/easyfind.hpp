#include <vector>
#include <stdexcept>

template <typename T>
int easyfind(std::vector<T> & vec, int x)
{
    int i = 0;
    for ( typename std::vector<T>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (vec[i] == x)
            return (i);
        i++;
    }
    return -1;
}