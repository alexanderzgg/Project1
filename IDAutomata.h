//
// Created by Alex on 1/30/2021.
//

#ifndef PROJECT_1_IDAUTOMATA_H
#define PROJECT_1_IDAUTOMATA_H

#include "Automaton.h"
#include "Token.h"

class IDAutomaton :
        public Automaton
{
private:

public:
    IDAutomaton(TokenType type) : Automaton(type) {
        this->type = type;
    }
    int Start(const std::string& input);
    void s0(std::string input);
    void s1(std::string input);
};

#endif //PROJECT_1_IDAUTOMATA_H
