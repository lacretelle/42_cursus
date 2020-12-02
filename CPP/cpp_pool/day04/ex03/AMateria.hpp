#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
private:
    std::string const   _type;
    unsigned int        _xp;

public:
    AMateria();
    AMateria(std::string const &type);
    AMateria(AMateria const &);
    AMateria & operator=(AMateria const &);
    virtual~AMateria();

    std::string const & getType() const;
    unsigned int        getXP() const;
    void                setXP(unsigned int);

    virtual AMateria    *clone() const = 0;
    virtual void        use(ICharacter& target) = 0;
};

#endif