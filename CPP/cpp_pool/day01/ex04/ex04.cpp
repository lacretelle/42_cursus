#include <iostream>

int main(){
std::string str = "HI THIS IS BRAIN";

std::string*   sPtr = &str;
std::string&   sRef = str;

std::cout << "Sentence displays with pointer: " << *sPtr << std::endl;
std::cout << "Sentence displays with reference: " << sRef << std::endl;
}