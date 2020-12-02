#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <string>
# include <iostream>

class Enemy
{
    protected:
        int             _hp;
        std::string     _type;

    public:
        Enemy();
        Enemy(int hp, std::string const & type);
        Enemy(Enemy const &);
        Enemy & operator=(Enemy const &);
        virtual ~Enemy();

        std::string getType() const;
        int getHP() const;
        virtual void takeDamage(int);
};

#endif