#include "iter.cpp"

int main(void)
{
    int arr[5] = {0, 1, 2, 3, 4};
    iter(arr, 5, f);

    std::string tab[4] = {"chaine1", "chaine2", "chaine3", "chaine4"};
    iter(tab, 4, f);
    return 0;
}