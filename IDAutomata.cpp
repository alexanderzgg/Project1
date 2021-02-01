//
// Created by Alex on 1/30/2021.
//

#include "IDAutomata.h"
int IDAutomaton::Start(const std::string& input)
{
    inputRead = 0;
    s0(input);
    return inputRead;
}
void IDAutomaton::s0(std::string input)
{
    if(isalpha(input.at(0)))
    {
        inputRead++;
        s1(input);
    }
}
void IDAutomaton::s1(std::string input)
{
    if(isalpha(input.at(inputRead)) || isalnum(input.at(inputRead)))
    {
        inputRead++;
        s1(input);
    }
    else
    {
        return;
    }
}