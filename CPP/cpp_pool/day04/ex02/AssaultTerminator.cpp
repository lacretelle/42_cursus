#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
    std::cout << "* teleports from space *" << std::endl;
}
AssaultTerminator::AssaultTerminator(AssaultTerminator const &src)
{
    std::cout << "copy" << std::endl;
    *this = src;
}
AssaultTerminator & AssaultTerminator::operator=(AssaultTerminator const &src)
{
    std::cout << "ENTER in operstor =" << std::endl;
    (void)src;
    return *this;
}
AssaultTerminator::~AssaultTerminator()
{
    std::cout << "I’ll be back ..." << std::endl;
}

ISpaceMarine *AssaultTerminator::clone() const
{
    return new AssaultTerminator(*this);
}
void AssaultTerminator::battleCry() const
{
    std::cout << "This code is unclean. Purify it !" << std::endl;
}
void AssaultTerminator::rangedAttack() const
{
    std::cout << "* does nothing *" << std::endl;
}
void AssaultTerminator::meleeAttack() const
{
    std::cout << "** attaque with chainfists *" << std::endl;
}