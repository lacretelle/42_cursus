#include "ZombieEvent.hpp"

int main()
{
    ZombieEvent zevent = ZombieEvent();
    zevent.setZombieType("powerfull");

    Zombie *z1 = zevent.newZombie("firstOfAll");
    Zombie *z2 = zevent.newZombie("theCaptain");

    zevent.randomChump();
    zevent.randomChump();
    zevent.randomChump();

    z1->advert();
    z2->advert();

    zevent.randomChump();
    zevent.randomChump();

    delete (z1);
    delete (z2);

    return 0;
}