#include <string>
#include <cstdlib>
#include <iostream>
// std::srand(std::time(NULL));
char *pickStringRand(char *str)
{
    const char alphanum[] =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int i = 0;
    while (i < 8)
    {
        str[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
        i++;
    }
    str[i] = 0;
    return str;
}

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

void *serialize(void)
{
    Data *data = new Data;
    char str[9];
    int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    data->s1 = pickStringRand(str);
    data->n = num[rand() % 10];
    data->s2 = pickStringRand(str);
    std::cout << std::endl
              << "Serialized" << std::endl;
    std::cout << "s1: " << data->s1 << std::endl;
    std::cout << "n:  " << data->n << std::endl;
    std::cout << "s2: " << data->s2 << std::endl;
    return reinterpret_cast<void *>(data);
}

Data *deserialize(void *raw)
{
    return reinterpret_cast<Data *>(raw);
}

int main()
{
    void *addr = serialize();
    Data *data = deserialize(addr);
    std::cout << std::endl
              << "Deserialized" << std::endl;
    std::cout << "s1: " << data->s1 << std::endl;
    std::cout << "n:  " << data->n << std::endl;
    std::cout << "s2: " << data->s2 << std::endl;
    delete data;
    return 0;
}