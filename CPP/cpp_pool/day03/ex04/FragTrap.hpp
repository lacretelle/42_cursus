#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const &);
        FragTrap & operator=(FragTrap const &);
        ~FragTrap();

        void        vaulthunter_dot_exe(std::string const & target);
        void        attack1(std::string const &target);
        void        attack2(std::string const &target);
        void        attack3(std::string const &target);
        void        attack4(std::string const &target);
        void        attack5(std::string const &target);
};

#endif