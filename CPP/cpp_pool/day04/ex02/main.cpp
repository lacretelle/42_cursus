#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main()
{
    ISpaceMarine *bob = new TacticalMarine;
    ISpaceMarine *timi = new TacticalMarine;
    ISpaceMarine *tod = new TacticalMarine;
    ISpaceMarine *jim = new AssaultTerminator;
    ISpaceMarine *john = new AssaultTerminator;
    ISpaceMarine *jules = new AssaultTerminator;
    ISpaceMarine *josh = new AssaultTerminator;
    ISpaceMarine *test1 = josh->clone();
test1->meleeAttack();
    ISquad *vlc = new Squad;
    ISquad *testSquad = new Squad;
    Squad lcv;
    ISquad *clv;

    testSquad->push(timi);
    testSquad->push(tod);
    
    lcv.push(john);

    vlc->push(bob);
    vlc->push(jim);

    *testSquad = *vlc;
    clv = new Squad(lcv);
    clv->push(jules);
    clv->push(josh);
    delete vlc;
    for (int i = 0; i < clv->getCount(); ++i)
    {
        ISpaceMarine *cur = clv->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    delete testSquad;
    delete clv;
    return 0;
}