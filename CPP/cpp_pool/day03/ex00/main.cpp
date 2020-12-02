#include "FragTrap.hpp"

int main()
{
    FragTrap uno = FragTrap("Uno");
    FragTrap dos = FragTrap("Dos");
    FragTrap timi = FragTrap("timi");
    FragTrap tod = FragTrap("tod");

    uno.rangedAttack(dos.getName());
    dos.takeDamage(20);
    dos.meleeAttack(timi.getName());
    timi.takeDamage(30);
    dos.meleeAttack(uno.getName());
    uno.takeDamage(30);
    uno.rangedAttack(tod.getName());
    tod.takeDamage(20);
    uno.meleeAttack(dos.getName());
    dos.takeDamage(30);
    uno.rangedAttack(tod.getName());
    tod.takeDamage(20);
    uno.rangedAttack(timi.getName());
    timi.takeDamage(20);
    dos.meleeAttack(uno.getName());
    uno.takeDamage(30);
    dos.meleeAttack(uno.getName());
    uno.takeDamage(30);
    dos.meleeAttack(uno.getName());
    uno.takeDamage(30);
    dos.meleeAttack(uno.getName());
    uno.takeDamage(30);
    dos.takeDamage(0);

    uno.beRepaired(50);
    dos.beRepaired(50);
    dos.beRepaired(50);

    uno.vaulthunter_dot_exe(tod.getName());
    dos.vaulthunter_dot_exe(timi.getName());
    uno.vaulthunter_dot_exe(dos.getName());
    timi.vaulthunter_dot_exe(dos.getName());
    tod.vaulthunter_dot_exe(timi.getName());
    uno.vaulthunter_dot_exe(dos.getName());
    uno.vaulthunter_dot_exe(timi.getName());
    uno.vaulthunter_dot_exe(dos.getName());
    uno.vaulthunter_dot_exe(timi.getName());
    return 0;
}