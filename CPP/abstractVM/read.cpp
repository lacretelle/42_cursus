#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "read.hpp"
#include "exception.hpp"

Read::Read()
{
std::cout << " ENTER IN CONSTRUCTOR READ: " << this->tokens.size() << std::endl;
}
Read::Read(Read const &src) { *this = src; }
Read &Read::operator=(Read const &src)
{
    this->tokens = src.tokens;
    return *this;
}
Read::~Read()
{
    if (!(this->tokens.empty()))
    {
        for (std::vector<Token*>::iterator i = this->tokens.begin(); i != this->tokens.end(); i++)
            delete *i;
        
    }
}

std::vector<std::string> Read::getWord(std::string l)
{
    std::string word;
    std::istringstream str(l);
    std::vector<std::string> items;
    while (str >> word)
        items.push_back(word);
    return items;
}

bool Read::readLine(std::string line, size_t nb)
{
    Lexer lex;
    std::vector<std::string> items;
    line = lex.searchComment(line);
    // CUT LINE TO GET EACH WORDS
    if (!line.empty())
    {
        items = getWord(line);
        if (!items.empty())
        {
            for (unsigned int i = 0; i < items.size(); i++)
            {
                Token *res = lex.tokenised(items.at(i), nb);
                if (!(res->getTokenValue().empty()))
                {
                    this->tokens.push_back(res);
                }
            }
            return true;
        }
    }
    return false;
}

// lecture phrase par phrase
// gestion erreur
void Read::readFile(char *file)
{
    std::ifstream streamRead(file);
    if (streamRead)
    {
        std::string line;
        size_t nbLine = 0;
        while (std::getline(streamRead, line))
        {
            if (readLine(line, nbLine))
                nbLine++;
        }
    }
    else
    {
        throw Exception(OPENIMPOSSIBLE, file, 0);
    }
}

void Read::readInput()
{
    std::string line;
    size_t nbLine = 0;
    std::vector<std::string> items;
    while (std::getline(std::cin, line))
    {
        // STOP READING IF FIND ;;
        if (line.compare(";;") == 0)
            return;
        if (readLine(line, nbLine))
            nbLine++;
    }
}