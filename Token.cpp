//
// Created by Alex on 1/23/2021.
//

#include "Token.h"
#include <string>

//Converts this instance's values into a string in the output format
std::string Token::ToString()
{
    std::string toOutput = "(" + TypeToString(this->tokenType) + ",\"" +
            this->tokenValue + "\"" + "," +  std::to_string(this->lineNumber) + ")";
    return toOutput;
}

//Converts the enum token type into it's corresponding string.
std::string Token::TypeToString(TokenType type)
{
    switch (type) {
        case COMMA:
            return "COMMA";
            break;
        case PERIOD:
            return "PERIOD";
            break;
        case Q_MARK:
            return "Q_MARK";
            break;
        case LEFT_PAREN:
            return "LEFT_PAREN";
            break;
        case RIGHT_PAREN:
            return "RIGHT_PAREN";
            break;
        case COLON:
            return "COLON";
            break;
        case COLON_DASH:
            return "COLON_DASH";
            break;
        case MULTIPLY:
            return "MULTIPLY";
            break;
        case ADD:
            return "ADD";
            break;
        case SCHEMES:
            return "SCHEMES";
            break;
        case FACTS:
            return "FACTS";
            break;
        case RULES:
            return "RULES";
            break;
        case QUERIES:
            return "QUERIES";
            break;
        case ID:
            return "ID";
            break;
        case STRING:
            return "STRING";
            break;
        case COMMENT:
            return "COMMENT";
            break;
        case UNDEFINED:
            return "UNDEFINED";
            break;
        case END:
            return "EOF";
            break;
        }
    return "ERROR";
}