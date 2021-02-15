//
// Created by Alex on 1/23/2021.
//

#ifndef PROJECT_1_TOKEN_H
#define PROJECT_1_TOKEN_H

#include <iostream>

enum TokenType {COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS,
    RULES, QUERIES, ID, STRING, COMMENT, UNDEFINED, END};

class Token {
public:
    Token(TokenType type, std::string value, int line)
    {
        tokenType = type;
        lineNumber = line;
        tokenValue = value;
    }
    std::string ToString();
    std::string TypeToString(TokenType type);
    TokenType getTok();
    std::string tokenValue;

private:

    int lineNumber;
    TokenType tokenType;
};




#endif //PROJECT_1_TOKEN_H
