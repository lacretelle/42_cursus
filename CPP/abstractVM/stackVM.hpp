#ifndef STACK_VM_HPP
# define STACK_VM_HPP
# include <stack>
# include <deque>

template < class T, class Container = std::deque<T> >
class StackVM : public std::stack<T, Container>
{
public:
    StackVM() : std::stack<T, Container>() {}
    StackVM(const Container &src) : std::stack<T, Container>(src) { *this = src; }
    StackVM<T> &operator=(StackVM const &src)
    {
        if (this != &src)
            (void)src;
        return *this;
    }
    ~StackVM<T>() {}
    typedef typename Container::iterator iterator;
    typename Container::iterator begin(void) { return this->c.begin(); };
    typename Container::iterator end(void) { return this->c.end(); };
    void clear(){ return this->c.clear();}
};

#endif