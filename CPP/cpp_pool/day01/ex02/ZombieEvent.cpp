#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) {
    std::cout << "ZombieEvent is activated." << std::endl;
}
ZombieEvent::~ZombieEvent(void) {
    std::cout << "ZombieEvent is desactivated." << std::endl;

}

void ZombieEvent::setZombieType(std::string type)
{
    this->_type = type;
}

Zombie *ZombieEvent::newZombie(std::string name)
{
    Zombie *newOne = new Zombie(name, this->_type);
    return newOne;
}

void ZombieEvent::randomChump(void)
{
    std::string zombieName[] = {"lucille", "rick", "negan", "daryl",
                                "glenn", "maggie", "carol", "michonne", "beth", "rosita", "jesus", "morgan", "hershel"};
    std::string name = zombieName[std::rand() % 13];
    Zombie newRandom = Zombie(name, "destructor");
    newRandom.advert();
}