#ifndef TOKEN_HPP
# define TOKEN_HPP
# include <string>

enum eToken
{
    OPERATION,
    ASSERTORPUSH,
    ACTION,
    NUMBER,
    EXIT,
    UNKNOWN
};

class Token
{
public:
    Token();
    Token(size_t, eToken type, std::string val, std::string nb);
    Token(Token const &);
    Token &operator=(Token const &);
    ~Token();

    eToken getTokenType() const;
    std::string getTokenValue() const;
    size_t getTokenLine() const;
    std::string getTokenNb() const;

private:
    size_t _line;
    eToken _type;
    std::string _value;
    std::string _nb;
};

#endif