#ifndef READ_HPP
# define READ_HPP
# include <string>
# include <vector>
# include "lexer.hpp"

class Read
{
    public:        
        std::vector<Token*>   tokens;

        Read();
        Read(Read const &);
        Read & operator=(Read const &);
        ~Read();

        std::vector<std::string>    getWord(std::string);
        bool    readLine(std::string line, size_t nb);
        void    readInput();
        void    readFile(char* file);
};
#endif