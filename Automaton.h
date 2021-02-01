//
// Created by Alex on 1/23/2021.
//

#ifndef PROJECT_1_AUTOMATON_H
#define PROJECT_1_AUTOMATON_H

#include "Token.h"

class Automaton
{
protected:
    int inputRead = 0;
    int newLines = 0;
    TokenType type;
    bool isUndefined;
public:
    Automaton(TokenType type) {
        this->type = type;
        isUndefined = false;
    }
// Start the automaton and return the number of characters read
// read == 0 indicates the input was rejected
// read > 0 indicates the input was accepted
    virtual int Start(const std::string& input) = 0;
    virtual Token* CreateToken(std::string input, int lineNumber)
    {
        if(isUndefined)
        {
            return new Token(UNDEFINED, input, lineNumber);
        }
        return new Token(type, input, lineNumber);
    }
    virtual int NewLinesRead() const { return newLines; }
};

#endif //PROJECT_1_AUTOMATON_H
