#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <string>
# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
    private:
        std::string _name;
        int         _ap;
        AWeapon*    _weapon;

    public:
        Character();
        Character(std::string const & name);
        Character(Character const &);
        Character & operator=(Character const &);
        ~Character();

        void recoverAP();
        void equip(AWeapon*);
        void attack(Enemy*);
        std::string getName() const;
        int         getAP() const;
        AWeapon*    getAWeapon() const;
};
std::ostream & operator<<(std::ostream & o, Character const c);
#endif