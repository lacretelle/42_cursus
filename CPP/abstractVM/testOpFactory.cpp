#include "OperandFactory.hpp"
#include "eOperandType.hpp"
#include <iostream>

int main()
{
    eOperandType e = Int16;
    OperandFactory opFac;
    std::cout << "Here in main" << std::endl;
    const IOperand *test1 =  opFac.createOperand(e, "987");
(void)test1;
return 0;
}