//
// Created by Alex on 1/23/2021.
//

#include "MatcherAutomaton.h"
int MatcherAutomaton::Start(const std::string& input) {
    bool isMatch = true;
    newLines = 0;
    inputRead = 0; // member variable inherited from Automaton class
    for (int i = 0; i < (int)toMatch.size() && isMatch; i++) {
        if (input[i] != toMatch[i]) {
            isMatch = false;
        }
        if(input[i] == '\n')
        {
            newLines++;
        }
    }
    if (isMatch) {
        inputRead = toMatch.size();
    }
    return inputRead;
}