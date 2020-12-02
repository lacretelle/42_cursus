
#ifndef PONY_H
# define PONY_H
# include <iostream>
# include <string>

class Pony
{
public:
    Pony(std::string name, std::string color, std::string sign);
    ~Pony(void);

    std::string getName(void);
    std::string getColor(void);
    std::string getSign(void);
    void        setColor(std::string color);
    void        setSign(std::string sign);

private:
    std::string _name;
    std::string _color;
    std::string _sign;
};

#endif