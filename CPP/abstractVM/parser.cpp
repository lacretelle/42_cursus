#include "parser.hpp"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>

Parser::Parser() {}
Parser::Parser(Parser const &src) { *this = src; }
Parser &Parser::operator=(Parser const &src)
{
    if (this != &src)
        (void)src;
    return *this;
}
Parser::~Parser() {}

/*
* IF OP => plus de 2 dans la stack ! (not <= 1)
*/
void Parser::parseOperation(Token *token, size_t sizeStack)
{
    if (sizeStack == 0)
        throw Exception(OPIMPOSSIBLE, "this stack is empty", token->getTokenLine());
    if (sizeStack < 2)
        throw Exception(OPIMPOSSIBLE, "this stack contains less than two numbers", token->getTokenLine());
}
/*
* PUSH OK 
* ASSERT OR OTHER ACTION => MIN 1 INPUT 
*/
void Parser::parseAction(Token *token, size_t sizeStack)
{
    if (sizeStack == 0 && (token->getTokenValue().compare("assert") == 0 || token->getTokenType() == ACTION))
    {
        throw Exception(ACTIMPOSSIBLE, "this stack is empty", token->getTokenLine());
    }
}

/*
* CHECK IF JUST DIGIT AND ACCEPT +/- AT THE START AND A DOT
*/
size_t checkIsDigit(Token *t)
{
    size_t i = 0;
    std::string number = t->getTokenNb();
    size_t nbDot = 0;
    while (i < number.size())
    {
        if (number.compare(0, 1, "-") == 0)
            i++;
        else if (number.compare(i, 1, ".") == 0 )
        {
            nbDot++;
            i++;
        }
        else if (isdigit(number[i]))
            i++;
        else
        {
            throw Exception(NOTNUMBER, number, t->getTokenLine());
        }
    }
    if (nbDot > 1)
    {
        throw Exception(NOTNUMBER, number, t->getTokenLine());
    }
    return nbDot;
}
/*
* CHECK ALL LIMITS
* INTEGER
* FLOAT
* INT8
* INT16
*/
void checkLimitsInteger(double tmpNb, Token *t)
{
    if (tmpNb < static_cast<double>(std::numeric_limits<int>::min()))
    {
        throw Exception(OVERFLOWLOW, t->getTokenNb(), t->getTokenLine());
    }
    else if (tmpNb > static_cast<double>(std::numeric_limits<int>::max()))
    {
        throw Exception(OVERFLOWHIGH, t->getTokenNb(), t->getTokenLine());
    }
}
void checkLimitsFloat(double tmpNb, Token *t)
{
    if (tmpNb < static_cast<double>(std::numeric_limits<float>::min()))
    {
        throw Exception(OVERFLOWLOW, t->getTokenNb(), t->getTokenLine());
    }
    else if (tmpNb > static_cast<double>(std::numeric_limits<float>::max()))
    {
        throw Exception(OVERFLOWHIGH, t->getTokenNb(), t->getTokenLine());
    }
}
void CheckLimitInt8(double tmpNb, Token *t)
{
    if (tmpNb < -128)
    {
        throw Exception(OVERFLOWLOW, t->getTokenNb(), t->getTokenLine());
    }
    else if (tmpNb > 127)
    {
        throw Exception(OVERFLOWHIGH, t->getTokenNb(), t->getTokenLine());
    }
}
void CheckLimitInt16(double tmpNb, Token *t)
{
    if (tmpNb < -32768)
    {
        throw Exception(OVERFLOWLOW, t->getTokenNb(), t->getTokenLine());
    }
    else if (tmpNb > 32767)
    {
        throw Exception(OVERFLOWHIGH, t->getTokenNb(), t->getTokenLine());
    }
}
/*
* IF NUMBER => if it correspond to type!! AND NOT EMPTY VALUE
*/
void Parser::parseNumber(Token *t)
{
    std::string number = t->getTokenNb();
    double tmpNb;
    size_t nbDot = checkIsDigit(t);
    // TRY => STD::STOD => TRANSFORM IN DOUBLE
    try
    {
        tmpNb = std::stod(number);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    // LIMITS OF INTEGER AND FLOAT
    if (t->getTokenValue() == "int8" || t->getTokenValue() == "int16" || t->getTokenValue() == "int32")
        checkLimitsInteger(tmpNb, t);
    else if (t->getTokenValue() == "float")
        checkLimitsFloat(tmpNb, t);
    // LIMITS INTEGER 8 & 16
    if (nbDot == 0 && t->getTokenValue().compare("int8") == 0)
        CheckLimitInt8(tmpNb, t);
    if (nbDot == 0 && t->getTokenValue().compare("int16") == 0)
        CheckLimitInt16(tmpNb, t);
}
/*
* CHECK TOKEN BY TOKEN SIMPLE PARSING
*/
void Parser::checkAll(Token *t, size_t sizeStack)
{
    if (t->getTokenType() == OPERATION)
        parseOperation(t, sizeStack);
    else if (t->getTokenType() == ASSERTORPUSH || t->getTokenType() == ACTION)
        parseAction(t, sizeStack);
    else if (t->getTokenType() == NUMBER)
        parseNumber(t);
    else if (t->getTokenType() == UNKNOWN)
        throw Exception(INVALIDINPUT, "", t->getTokenLine());
}
/*
* COUNT EACH TOKEN BY LINE
* CHECK IF NUMBER WRITE WITH ASSERT OR PUSH
*/
void Parser::countInstructionByLine(std::vector<Token *> vec)
{
    size_t maxLine = vec.back()->getTokenLine();
    size_t i = 0;
    while (i <= maxLine)
    {
        // count nb token by each line
        size_t count = 0;
        for (size_t it = 0; it < vec.size(); it++)
        {
            if (vec[it]->getTokenLine() == i)
            {
                count++;
                if (count > 2)
                {
                    throw Exception(INVALIDINPUT, "", i);
                }
                if (count == 0 && vec[it]->getTokenType() == NUMBER)
                {
                    throw Exception(BADINSTRUCTION, "enter a number alone", i);
                }
                if (count == 2)
                {
                    if (!(vec[it]->getTokenType() == NUMBER) || !(vec[it - 1]->getTokenType() == ASSERTORPUSH))
                    {
                        throw Exception(BADINSTRUCTION, "instruction invalid", i);
                    }
                }
            }
        }
        i++;
    }
}