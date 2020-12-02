#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <string>
# include <iostream>

class Victim
{
    public:
        Victim(std::string name);
        Victim(Victim const &);
        Victim & operator=(Victim const &);
        ~Victim();

        std::string     getName() const;
        void virtual    getPolymorphed() const;

    protected:
        std::string _name;
        Victim();
};

std::ostream & operator<<(std::ostream & o, Victim const &);
#endif