#ifndef SORCERER_HPP
# define SORCERER_HPP
# include <string>
# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
    public:
        Sorcerer(std::string name, std::string title);
        Sorcerer(Sorcerer const &);
        Sorcerer & operator=(Sorcerer const &);
        ~Sorcerer();

        std::string getName() const;
        std::string getTitle() const;
        void        polymorph(Victim const &) const;

    private:
        std::string _name;
        std::string _title;
        Sorcerer();
};
std::ostream & operator<<(std::ostream & o, Sorcerer const &);


#endif