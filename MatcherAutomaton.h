//
// Created by Alex on 1/23/2021.
//

#ifndef PROJECT_1_MATCHERAUTOMATON_H
#define PROJECT_1_MATCHERAUTOMATON_H

#include "Automaton.h"
#include "Token.h"

class MatcherAutomaton :
        public Automaton
{
private:
    std::string toMatch;
public:
    MatcherAutomaton(TokenType type, std::string toMatch, TokenType tokenType) : Automaton(type) {
        this->toMatch = toMatch;
        this->type = tokenType;
    }
    int Start(const std::string& input);
};
#endif //PROJECT_1_MATCHERAUTOMATON_H
