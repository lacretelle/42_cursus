#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include <string>

typedef struct  s_inventory
{
    AMateria            *mat;
    struct s_inventory  *next;
}               t_inventory;

class Character : public ICharacter
{
public:
    Character();
    Character(std::string name);
    Character(Character const &);
    Character & operator=(Character const &);
    ~Character();

    std::string const & getName() const;
    AMateria*           getMateria(int n) const;
    int                 getCountMateria() const;
    void                equip(AMateria *m);
    void                unequip(int idx);
    void                use(int idx, ICharacter &target);

private:
    std::string     _name;
    t_inventory*    _inventory;
    int             _countMateria;
};

#endif