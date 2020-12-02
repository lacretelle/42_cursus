#ifndef SQUAD_HPP
# define SQUAD_HPP
# include "ISquad.hpp"
# include <string>

typedef struct  s_container
{
    ISpaceMarine        *unit;
    struct s_container  *next;
}               t_container;

class Squad : public ISquad
{
private:
    int             _countUnit;
    t_container*    _squadUnit;

public:
    Squad();
    Squad(Squad const &);
    Squad &operator=(Squad const &);
    ~Squad();

    int             getCount() const;
    ISpaceMarine*   getUnit(int) const;
    int             push(ISpaceMarine *);
};

#endif
