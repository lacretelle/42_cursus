#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP
# include "IMateriaSource.hpp"
# include <iostream>

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource(MateriaSource const &);
        MateriaSource & operator=(MateriaSource const &);
        ~MateriaSource();
        
        void        learnMateria(AMateria*);
        AMateria*   createMateria(std::string const & type);

        int         getCountSource() const;
        AMateria*   getMateria(int n) const;

    private:
        AMateria*   _matSource[4];
        int         _countSource;     
};

#endif