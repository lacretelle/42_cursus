#include "Brain.hpp"

Brain::Brain() : _frontalLobe("1"), _parietalLobe("2"), _temporalLobe("3"), _occipitalLobe("4")
{
    std::cout << "A brain is constructed" << std::endl;
    std::stringstream ss;
    const void *address = (const void *)this;
    ss << address;
    this->_address = ss.str();
}
Brain::~Brain()
{
    std::cout << "A brain is destructed" << std::endl;
}

std::string Brain::identify(void)
{
    return this->_address;
}
