#ifndef PEON_HPP
# define PEON_HPP
# include "Victim.hpp"

class Peon : public Victim
{
    public:
        Peon(std::string name);
        Peon(Peon const &);
        Peon & operator=(Peon const &);
        ~Peon();

        void    getPolymorphed() const;

    protected:
        std::string _name;
    private:
        Peon();
};

std::ostream & operator<<(std::ostream & o, Peon const &);
#endif