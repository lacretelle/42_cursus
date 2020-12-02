#include "Human.hpp"

Human::Human() : _Brain(new Brain())
{
    std::cout << "A human is constructed" << std::endl;
}
Human::~Human(void)
{
    std::cout << "A human is destructed" << std::endl;
}

std::string Human::identify(void) const
{
    return this->_Brain->identify();
}

Brain Human::getBrain(void) const
{
    return *(this->_Brain);
}