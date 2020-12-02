#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <cctype>
#include "lexer.hpp"

Lexer::Lexer() {}
Lexer::Lexer(Lexer const &src) { *this = src; }
Lexer &Lexer::operator=(Lexer const &src)
{
    if (this != &src)
        (void)src;
    return *this;
}
Lexer::~Lexer() {}

/*
* TOKENISED ALL LINE 
*/
Token *Lexer::tokenised(std::string s, size_t nbLine)
{
    std::regex op("add|sub|mul|div|mod");
    std::regex pushOrAssert("push|assert");
    std::regex act("pop|dump|print");
    std::regex nb("(int8|int16|int32|float|double)[(][[0-9]*.[0-9]*[)]");
    std::regex exit("exit");
    std::string nbType = s;
    std::string numb = "";    
    eToken e = UNKNOWN;
    if (!(s.empty()))
    {
        if (std::regex_match(s, op))
            e = OPERATION;
        else if (std::regex_match(s, pushOrAssert))
            e = ASSERTORPUSH;
        else if (std::regex_match(s, act))
            e = ACTION;
        else if (std::regex_match(s, nb))
        {
            e = NUMBER;
            size_t foundSt = s.find("(");
            size_t foundEnd = s.find(")");
            if (foundSt != std::string::npos && foundEnd != std::string::npos)
            {
                nbType = s.substr(0, foundSt);
                numb = s.substr(foundSt + 1, foundEnd - foundSt - 1);
            }
        } else if (std::regex_match(s, exit))
            e = EXIT;
    }
    return new Token(nbLine, e, nbType, numb);
}

/*
* SEARCH IF LINE CONTAINS COMMENT
* yes => remove comment
* no, return std::string in param
*/
std::string Lexer::searchComment(std::string line)
{
    std::string res = line;
    size_t found = line.find(";");
    if (found == 0)
        res = "";
    else if (found != std::string::npos)
        res = res.substr(0, found);
    return res;
}