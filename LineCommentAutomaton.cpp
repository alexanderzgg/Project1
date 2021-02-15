//
// Created by Alex on 1/30/2021.
//

#include "LineCommentAutomaton.h"
int LineCommentAutomaton::Start(const std::string& input)
{
    inputRead = 0;
    s0(input);
    return inputRead;
}
void LineCommentAutomaton::s0(std::string input)
{
    if(input.at(inputRead) == '#')
    {
        inputRead++;
        s1(input);
    }
}
void LineCommentAutomaton::s1(std::string input)
{
    if(input.at(inputRead) != '\n' && input.at(inputRead) != -1)
    {
        inputRead++;
        s1(input);
    }
}