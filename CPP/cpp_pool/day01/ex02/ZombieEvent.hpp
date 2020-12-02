#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

# include <cstdlib>
# include "Zombie.hpp"

class ZombieEvent
{
public:
    ZombieEvent(void);
    ~ZombieEvent(void);
    void    setZombieType(std::string type);
    Zombie  *newZombie(std::string name);
    void    randomChump(void);

private:
    std::string _type;
};

#endif