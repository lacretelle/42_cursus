#include "ZombieHorde.hpp"

int main()
{
    int n = std::rand() % 30;

    std::cout << "We will create an horde of " << n << " zombies, Good luck !" << std::endl;

    ZombieHorde horde = ZombieHorde(n);
    horde.announce();

    return 0;
}