//
// Created by Alex on 1/30/2021.
//

#include "CommentAutomaton.h"
int CommentAutomaton::Start(const std::string& input)
{
    isUndefined = false;
    inputRead = 0;
    newLines = 0;
    s0(input);
    return inputRead;
}
void CommentAutomaton::s0(std::string input)
{
    if(input.at(inputRead) == '#')
    {
        inputRead++;
        s1(input);
    }
}
void CommentAutomaton::s1(std::string input)
{
    if(input.at(inputRead) == '|')
    {
        inputRead++;
        s2(input);
    }
    else if(input.at(inputRead) != '|')
    {
        inputRead++;
        s4(input);
    }
}

void CommentAutomaton::s2(std::string input)
{

    if(input.at(inputRead) == '|')
    {
        inputRead++;
        s3(input);
    }
    else
    {
        //If we come across a new line
        if(input.at(inputRead) == '\n') {
            newLines ++;
        }
        //EOF reached
        if(input.at(inputRead) == -1)
        {
            isUndefined = true;
            return;
        }
        inputRead++;
        s2(input);
    }
}

void CommentAutomaton::s3(std::string input)
{
    if(input.at(inputRead) == '#')
    {
        inputRead++;
        return;
    }
    else
    {
        //EOF reached
        if(input.at(inputRead) == -1)
        {
            isUndefined = true;
            return;
        }

        inputRead++;
        s2(input);
    }
}

void CommentAutomaton::s4(std::string input)
{
    if(input.at(inputRead) != -1 && input.at(inputRead) != '\n')
        {
            inputRead ++;
            s4(input);
        }
}