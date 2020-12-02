#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

int main()
{
    FragTrap uno = FragTrap("uno");
    FragTrap dos = FragTrap("dos");
    FragTrap timi = FragTrap("timi");

    ScavTrap tod = ScavTrap("tod");
    ScavTrap leo = ScavTrap("leo");

    NinjaTrap n1 = NinjaTrap("ninja-1");
    NinjaTrap n2 = NinjaTrap("ninja-2");

    uno.rangedAttack(dos.getName());
    dos.takeDamage(dos.getRangedAttackDamage());
    dos.meleeAttack(timi.getName());
    timi.takeDamage(timi.getMeleeAttackDamage());
    dos.meleeAttack(uno.getName());
    uno.takeDamage(uno.getMeleeAttackDamage());
    uno.meleeAttack(dos.getName());
    dos.takeDamage(dos.getMeleeAttackDamage());
    uno.rangedAttack(timi.getName());
    timi.takeDamage(timi.getRangedAttackDamage());
    dos.meleeAttack(uno.getName());
    uno.takeDamage(uno.getMeleeAttackDamage());
    dos.meleeAttack(uno.getName());
    uno.takeDamage(uno.getMeleeAttackDamage());
    dos.meleeAttack(uno.getName());
    uno.takeDamage(uno.getMeleeAttackDamage());
    dos.meleeAttack(uno.getName());
    uno.takeDamage(uno.getMeleeAttackDamage());
    dos.takeDamage(0);

    uno.beRepaired(50);
    dos.beRepaired(50);
    dos.beRepaired(50);

    tod.rangedAttack(leo.getName());
    leo.takeDamage(leo.getRangedAttackDamage());
    leo.meleeAttack(tod.getName());
    tod.takeDamage(tod.getMeleeAttackDamage());
    leo.meleeAttack(tod.getName());
    tod.takeDamage(tod.getMeleeAttackDamage());
    leo.meleeAttack(tod.getName());
    tod.takeDamage(tod.getMeleeAttackDamage());
    leo.meleeAttack(tod.getName());
    tod.takeDamage(leo.getMeleeAttackDamage());
    leo.takeDamage(0);

    leo.beRepaired(50);
    tod.beRepaired(50);
    tod.beRepaired(50);

    // uno.vaulthunter_dot_exe(timi.getName());
    // dos.vaulthunter_dot_exe(uno.getName());
    // uno.vaulthunter_dot_exe(dos.getName());
    // timi.vaulthunter_dot_exe(dos.getName());
    // dos.vaulthunter_dot_exe(timi.getName());
    // uno.vaulthunter_dot_exe(dos.getName());
    // uno.vaulthunter_dot_exe(timi.getName());
    // uno.vaulthunter_dot_exe(dos.getName());
    // uno.vaulthunter_dot_exe(timi.getName());
    
    // tod.challengeNewcomer();
    // tod.challengeNewcomer();
    // leo.challengeNewcomer();
    // leo.challengeNewcomer();

    n1.ninjaShoebox(uno);
    n1.ninjaShoebox(tod);
    n2.ninjaShoebox(dos);
    n2.ninjaShoebox(leo);
    return 0;
}