//
// Created by Alex on 1/30/2021.
//

#ifndef PROJECT_1_COMMENTAUTOMATON_H
#define PROJECT_1_COMMENTAUTOMATON_H


#include "Automaton.h"
#include "Token.h"

class CommentAutomaton :
        public Automaton
{
private:

public:
    CommentAutomaton(TokenType type) : Automaton(type) {
        this->type = type;
    }
    int Start(const std::string& input);
    void s0(std::string input);
    void s1(std::string input);
    void s2(std::string input);
    void s3(std::string input);
    void s4(std::string input);
};


#endif //PROJECT_1_COMMENTAUTOMATON_H
