#ifndef ABSTRACT_VM_HPP
# define ABSTRACT_VM_HPP
# include "read.hpp"
# include <iostream>
# include "IOperand.hpp"
#include "stackVM.hpp"

class AbstractVM
{
    public:
        AbstractVM();
        AbstractVM(AbstractVM const &);
        AbstractVM & operator=(AbstractVM const &);
        ~AbstractVM();

        StackVM<const IOperand*> stackVM;
        
        void    dispatcher(Read *r);
        void    addVM();
        void    subVM();
        void    mulVM();
        void    divVM();
        void    modVM();
        void    pushVM(Token *t);
        void    assertVM(Token *t);
        void    popVM();
        void    dumpVM();
        void    printVM();
        void    execute(Token *t, std::string exec);

};

#endif