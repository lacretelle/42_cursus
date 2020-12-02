#include "Character.hpp"
#include <iostream>

Character::Character() {}
Character::Character(std::string name) : _name(name), _inventory(NULL), _countMateria(0) {}
Character::Character(Character const &src)
{
    *this = src;
}
Character &Character::operator=(Character const &src)
{
    if (this != &src)
    {
        if (this->_inventory != NULL)
        {
            t_inventory *current = this->_inventory;
            t_inventory *tmp;
            while (current)
            {
                tmp = current->next;
                delete current->mat;
                delete current;
                current = tmp;
            }
            this->_inventory = NULL;
        }
        int n = 0;
        while (n < src.getCountMateria())
        {
            this->equip(src.getMateria(n)->clone());
            n++;
        }
        this->_name = src.getName();
    }
    return *this;
}
Character::~Character()
{
    if (this->_inventory != NULL)
    {
        t_inventory *current = this->_inventory;
        t_inventory *tmp;
        while (current)
        {
            tmp = current->next;
            delete current->mat;
            delete current;
            current = tmp;
        }
        this->_inventory = NULL;
    }
}
std::string const &Character::getName() const
{
    return this->_name;
}
AMateria* Character::getMateria(int n) const
{
    if (n >= 0 && n < 4)
    {
        int i = 0;
        t_inventory *current = this->_inventory;
        while (i < n)
        {
            current = current->next;
            i++;
        }
        return current->mat;
    }
    return NULL;
}
int Character::getCountMateria() const
{
    return this->_countMateria;
}
void Character::equip(AMateria *m)
{
    if (this->getCountMateria() < 4 && m)
    {
        t_inventory *newOne = new t_inventory;
        newOne->mat = m;
        newOne->next = NULL;
        if (this->getCountMateria() == 0)
            this->_inventory = newOne;
        else
        {
            t_inventory *current = this->_inventory;
            while (current->next)
                current = current->next;
            current->next = newOne;
        }
        this->_countMateria += 1;
    }
}
void Character::unequip(int idx)
{
    if (idx >= 0 && idx < this->getCountMateria())
    {
        t_inventory *current = this->_inventory;
        while (idx--)
            current = current->next;
        if (current != NULL)
            current->mat = NULL;
        t_inventory *list = this->_inventory;
        if (list->mat == NULL)
        {
            this->_inventory = list->next;
            list = NULL;
        }
        else
        {
            t_inventory *tmp;
            while (list && list->next)
            {
                if (list->next->mat == NULL)
                {
                    tmp = list->next;
                    list->next = tmp->next;
                    delete tmp;
                    // return;
                }
                list = list->next;
            }
        }
        this->_countMateria -= 1;
    }
}
void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < this->getCountMateria())
    {
        if (this->getMateria(idx))
            this->getMateria(idx)->use(target);
    }
}
