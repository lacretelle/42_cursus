#include "Pony.hpp"

void ponyOnTheStack()
{
    std::string s;
    Pony first = Pony("First_princess_stack", "red", "aquarius");
    std::cout << "Pony " << first.getName() << " is " << first.getColor() << std::endl;
    std::cout << "Would like to change color ? Enter a another color if you want." << std::endl;
    std::getline(std::cin, s);
    if (s.size() > 0)
        first.setColor(s);
    std::cout << "Now, Pony " << first.getName() << " is " << first.getColor() << std::endl;
}
void ponyOnTheHeap()
{
    std::string s;
    Pony *second = new Pony("Second_princess_heap", "blue", "pisces");
    std::cout << "Pony " << second->getName() << " is " << second->getSign() << std::endl;
    std::cout << "Would like to change its sign ? Enter a another sign if you want." << std::endl;
    std::getline(std::cin, s);
    if (s.size() > 0)
        second->setSign(s);
    std::cout << "Now, Pony " << second->getName() << " is " << second->getSign() << std::endl;
    delete second;
}
int main()
{   
    ponyOnTheStack();
    ponyOnTheHeap();

    return 0;
}
