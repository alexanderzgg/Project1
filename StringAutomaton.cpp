//
// Created by Alex on 1/30/2021.
//

#include "StringAutomaton.h"
int StringAutomaton::Start(const std::string& input)
{
    newLines = 0;
    inputRead = 0;
    isUndefined = false;
    s0(input);
    return inputRead;
}

void StringAutomaton::s0(std::string input)
{
    if(input.at(inputRead) == '\'')
    {
        inputRead ++;
        s1(input);
    }
}

void StringAutomaton::s1(std::string input)
{
    if(input.at(inputRead) != '\'')
    {

        //If we come across a new line
        if(input.at(inputRead) == '\n') {
            newLines ++;
        }
        //If we hit the EOF
        if(input.at(inputRead) == -1) {
            isUndefined = true;
            return;
        }
        inputRead ++;
        s1(input);
    }
    else
    {
        inputRead ++;
        s2(input);
    }
}

void StringAutomaton::s2(std::string input)
{
    if(input.at(inputRead) == '\'')
    {
        inputRead ++;
        s1(input);
    }
}