//
// Created by Alex on 1/30/2021.
//

#ifndef PROJECT_1_LINECOMMENTAUTOMATON_H
#define PROJECT_1_LINECOMMENTAUTOMATON_H


#include "Automaton.h"
#include "Token.h"

class LineCommentAutomaton :
        public Automaton
{
private:

public:
    LineCommentAutomaton(TokenType type) : Automaton(type) {
        this->type = type;
    }
    int Start(const std::string& input);
    void s0(std::string input);
    void s1(std::string input);
};

#endif //PROJECT_1_LINECOMMENTAUTOMATON_H
