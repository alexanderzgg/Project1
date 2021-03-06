//
// Created by Alex on 1/23/2021.
//

#include "Lexer.h"


void Lexer::Run(std::string input) {
    // NOTE: Lexer class needs a collection of machines and
    // an ordered collection to store the tokens generated
    lineNumber = 1;
    // While there are more characters to tokenize
    while(input.size() > 0)
    {

        maxRead = 0;
        maxAutomaton = automata.at(0);

        // TODO: you need to handle whitespace in between tokens

        while(isspace(input.at(0)))
        {
            if(isspace(input.at(0)))
            {
                if(input.at(0) == '\n')
                {
                    lineNumber++;
                }
                input.erase(0,1);
            }
        }


        // Here is the "Parallel" part of the algorithm
        // Each automaton runs with the same input
        for(unsigned i = 0; i < automata.size(); i++)
    {
        inputRead = automata.at(i)->Start(input);
        if (inputRead > maxRead)
        {
            maxRead = inputRead;
            maxAutomaton = automata.at(i);
        }
    }

    // Here is the "Max" part of the algorithm
    if (maxRead > 0)
    {
        newToken = maxAutomaton->CreateToken(input.substr (0,maxRead), lineNumber);
        lineNumber += maxAutomaton->NewLinesRead();

        //TODO
        //For lab 2 this if statement stops comments from being pushed onto the token vector.
        if(newToken->getTok() != COMMENT)
        {
            tokens.push_back(newToken);
        }

    }
    // No automaton accepted input; create invalid token
    else {

        maxRead = 1;
        std::string firstChar;
        firstChar.push_back(input.at(0));

        //EOF = -1
        if(input.at(0) == -1)
        {
            newToken = new Token(END, "", lineNumber);
        }
        //Otherwise undefined
        else{
            newToken = new Token(UNDEFINED, firstChar, lineNumber);
        }


        tokens.push_back(newToken);

    }
        input.erase(0,maxRead);
    }
}

std::vector<Token*> Lexer::SendTokens()
{
    return tokens;
}