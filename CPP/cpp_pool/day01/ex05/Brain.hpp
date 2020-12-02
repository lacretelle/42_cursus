#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <sstream>

class Brain
{
public:
    Brain(void);
    ~Brain(void);
    std::string identify(void);

private:
    std::string _address;
    std::string _frontalLobe;
    std::string _parietalLobe;
    std::string _temporalLobe;
    std::string _occipitalLobe;
};

#endif