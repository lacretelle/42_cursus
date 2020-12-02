#ifndef TACTICAL_MARINE_HPP
# define TACTICAL_MARINE_HPP
# include "ISpaceMarine.hpp"
# include <iostream>

class TacticalMarine : public ISpaceMarine
{
private:

public:
    TacticalMarine();
    TacticalMarine(TacticalMarine const &);
    TacticalMarine & operator=(TacticalMarine const &);
    ~TacticalMarine();
    virtual ISpaceMarine *clone() const;
    virtual void battleCry() const;
    virtual void rangedAttack() const;
    virtual void meleeAttack() const;
};

#endif