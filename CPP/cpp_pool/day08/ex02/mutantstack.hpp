#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP
# include <deque>
# include <stack>

template<typename T, typename Container = std::deque<T>>
class MutantStack
: public std::stack<T, Container>
{
    public:
        MutantStack();
        ~MutantStack();
        typedef Container<T> iterator;
        typename Container::iterator begin = c.begin();
        typename Container::iterator end = c.end();
};

#endif