#include "AWeapon.hpp"
#include "Enemy.hpp"
#include "Character.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main()
{
    Character *moi = new Character("moi");
    Character *captain = new Character("captain");

    std::cout << *moi;

    Enemy *b = new RadScorpion();
    Enemy *sup = new SuperMutant();
    Enemy *sup2 = new SuperMutant();

    AWeapon *pr = new PlasmaRifle();
    AWeapon *pf = new PowerFist();

    moi->equip(pr);
    std::cout << *moi;
    moi->equip(pf);

    captain->equip(pf);
    std::cout << *captain;

    moi->attack(b);
    std::cout << *moi;
    moi->equip(pr);
    std::cout << *moi;
    moi->attack(b);
    std::cout << *moi;

    captain->attack(sup);
    std::cout << *captain;
    captain->attack(sup);
    captain->attack(sup);
    captain->attack(sup);
    std::cout << *captain;
    
    captain->attack(b);
    std::cout << *captain;
    captain->attack(sup2);
    std::cout << *captain;
    captain->recoverAP();
    std::cout << *captain;
    captain->attack(sup2);
    return 0;
}