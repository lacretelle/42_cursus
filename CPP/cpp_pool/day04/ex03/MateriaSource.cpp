#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _countSource(0)
{
    for (int i = 0; i < 4; i++)
        this->_matSource[i] = NULL;
}
MateriaSource::MateriaSource(MateriaSource const &src)
{
    *this = src;
}
MateriaSource & MateriaSource::operator=(MateriaSource const & src)
{
    this->_countSource = src.getCountSource();
    for (int i = 0; i < src.getCountSource(); i++)
        this->_matSource[i] = src.getMateria(i);
    return *this;
}
// delete Materia ?
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < this->getCountSource(); i++)
    {
        // delete this->_matSource[i];
        this->_matSource[i] = NULL;
    }
}
int MateriaSource::getCountSource() const
{
    return this->_countSource;
}
AMateria*   MateriaSource::getMateria(int n) const
{
    return this->_matSource[n];
}
void MateriaSource::learnMateria(AMateria *m)
{
    if (this->getCountSource() < 4)
    {
        this->_matSource[this->getCountSource()] = m;
        this->_countSource += 1;
    }
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < this->getCountSource(); i++)
    {
        if (this->_matSource[i] != NULL && this->_matSource[i]->getType() == type)
            return this->_matSource[i]->clone();
    }
    return NULL;
}