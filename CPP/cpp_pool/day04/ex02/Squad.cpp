#include "Squad.hpp"
#include <iostream>

Squad::Squad() : _countUnit(0), _squadUnit(NULL)
{
    std::cout << "constructor " << std::endl;
}
Squad::Squad(Squad const &src)
{
    std::cout << " IN COPY " << std::endl;
    *this = src;
}
Squad &Squad::operator=(Squad const &src)
{
    std::cout << " BEFORE here in operator = getcount=> "  << src.getCount() << std::endl;
    if (&src != this)
    {
        t_container *nextUnit;
        for (int i = 0; i < this->getCount(); i++)
        {
            nextUnit = this->_squadUnit->next;
            this->_squadUnit = NULL;
            this->_squadUnit = nextUnit;
        }
        t_container *current = this->_squadUnit;
        for (int i = 0; i < src.getCount(); i++)
        {
            t_container *newOne = new t_container;
            newOne->unit = src.getUnit(i)->clone();
            newOne->next = NULL;
            current = newOne;
            current = current->next;
        }

        std::cout << " AFTER here in operator = " << std::endl;
    }
    return *this;
}
Squad::~Squad()
{
    t_container *nextUnit;
    for (int i = 0; i < getCount(); i++)
    {
        nextUnit = this->_squadUnit->next;
        delete this->_squadUnit->unit;
        this->_squadUnit = nextUnit;
    }
    this->_squadUnit = NULL;
    std::cout << "Destructor " << std::endl;
}

int Squad::getCount() const
{
    return this->_countUnit;
}
ISpaceMarine *Squad::getUnit(int n) const
{
    if (n >= 0 && n < this->getCount())
    {
        t_container *current = this->_squadUnit;
        for (int i = 0; i < n; i++)
            current = current->next;
        return current->unit;
    }
    return NULL;
}
int Squad::push(ISpaceMarine *unit)
{
    if (unit != NULL)
    {
        t_container *newNode = new t_container;
        newNode->unit = unit;
        newNode->next = NULL;
        if (this->getCount() == 0)
            this->_squadUnit = newNode;
        else
        {
            t_container *current = this->_squadUnit;
            while (current->next != NULL)
                current = current->next;
            current->next = newNode;
        }
        this->_countUnit += 1;
        return this->_countUnit;
    }
    return -1;
}