#ifndef PARSER_HPP
# define PARSER_HPP
# include <string>
# include "read.hpp"
# include "exception.hpp"

class Read;
class Parser
{
public:
    Parser();
    Parser(Parser const &);
    Parser &operator=(Parser const &);
    ~Parser();

    void    countInstructionByLine(std::vector<Token *> vec);
    void    checkAll(Token*, size_t sizeStack);
    void    parseOperation(Token* token, size_t sizeStack);
    void    parseAction(Token* token,size_t sizeStack);
    void    parseNumber(Token*);
};

#endif