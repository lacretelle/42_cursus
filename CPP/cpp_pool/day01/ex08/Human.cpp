#include "Human.hpp"

void Human::meleeAttack(std::string const &target)
{
    std::cout << "Mellee Attack on " << target << std::endl;
}
void Human::rangedAttack(std::string const &target)
{
    std::cout << "Ranged Attack on " << target << std::endl;
}
void Human::intimidatingShout(std::string const &target)
{
    std::cout << "Intimidating Shout on " << target << std::endl;
}
void Human::action(std::string const & action_name, std::string const &target)
{
    typedef void (Human::* fptr)(const std::string&);
    fptr ftab[3] = { &Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
// doesnt work
    *(ftab[action_name])(target);
}