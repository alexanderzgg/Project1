//
// Created by Alex on 1/23/2021.
//

#ifndef PROJECT_1_LEXER_H
#define PROJECT_1_LEXER_H
#include "Token.h"
#include "Automaton.h"
#include "MatcherAutomaton.h"
#include <vector>
#include <cctype>


class Lexer {
private:
    std::vector<Token*> tokens;
    std::vector<Automaton*> automata;
    Token* newToken;
    int lineNumber;
    int maxRead;
    int inputRead;
    Automaton* maxAutomaton;
public:
    Lexer() {
        tokens = std::vector<Token*>();
        automata = std::vector<Automaton*>();
// Add all of the Automaton instances
        automata.push_back(new MatcherAutomaton(STRING, "Facts", FACTS));
        automata.push_back(new MatcherAutomaton(STRING, "Rules", RULES));
        automata.push_back(new MatcherAutomaton(STRING, ",", COMMA));
        automata.push_back(new MatcherAutomaton(STRING, ".", PERIOD));
        automata.push_back(new MatcherAutomaton(STRING, "?", Q_MARK));
        automata.push_back(new MatcherAutomaton(STRING, "(", LEFT_PAREN));
        automata.push_back(new MatcherAutomaton(STRING, ")", RIGHT_PAREN));
        automata.push_back(new MatcherAutomaton(STRING, ":", COLON));
        automata.push_back(new MatcherAutomaton(STRING, ":-", COLON_DASH));
        automata.push_back(new MatcherAutomaton(STRING, "*", MULTIPLY));
        automata.push_back(new MatcherAutomaton(STRING, "+", ADD));
        automata.push_back(new MatcherAutomaton(STRING, "Schemes", SCHEMES));
        automata.push_back(new MatcherAutomaton(STRING, "Queries", QUERIES));

//automata.push_back(new ColonAutomaton());
//automata.push_back(new ColonDashAutomaton());
    //    ...
    }
// Other needed methods here
    void Run(std::string input);
    std::vector<Token*> SendTokens();

};

#endif