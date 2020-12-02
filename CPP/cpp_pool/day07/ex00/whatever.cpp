template<typename T>
void    swap(T & x, T & y)
{
    T c;
    c = x;
    x = y;
    y = c;
}

template<typename U>
U const &   min(U const & x, U const & y)
{
    return x < y ? x : y;
}

template<typename V>
V const &   max(V const & x, V const & y)
{
    return x > y ? x : y;
}