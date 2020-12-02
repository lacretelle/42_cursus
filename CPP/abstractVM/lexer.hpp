#ifndef LEXER_HPP
# define LEXER_HPP
# include <string>
# include "token.hpp"

class Lexer
{
public:
    Lexer();
    Lexer(Lexer const &);
    Lexer &operator=(Lexer const &);
    ~Lexer();

    Token*      tokenised(std::string s, size_t nbLine);
    std::string searchComment(std::string line);
};
#endif