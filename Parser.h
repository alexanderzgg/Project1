//
// Created by Alex on 2/8/2021.
//

#ifndef PROJECT_1_PARSER_H
#define PROJECT_1_PARSER_H

#include <vector>
#include "Token.h"
#include "DatalogProgram.h"
#include "Predicate.h"
#include "ExpressionParam.h"
#include "PlainParam.h"

class Parser {
public:
    Parser(std::vector<Token*> tokens)
    {
        tokensToParse = tokens;
        counter = 0;
    }
    int counter;
    //Functions for each non-terminal.
    void RunDatalogProgram();
    void SchemeList();
    void FactList();
    void RuleList();
    void QueryList();
    void Scheme();
    void Fact();
    void Rule();
    void Query();
    class Predicate* HeadPredicate();
    class Predicate* Predicate();
    void PredicateList(class Rule* rule);
    void ParameterList(class Predicate* pred);
    void StringList(class Predicate* pred);
    void IDList(class Predicate* pred);
    class Parameter* Parameter();
    class ExpressionParam* Expression();
    class Parameter* Operator();

    //Function that checks a token against a given terminal to see if it matches
    void Matcher(TokenType tokenType);
    //Function that checks the next token against a given type to see if it matches
    bool Next(TokenType tokenType);

private:
    DatalogProgram mainDatalog;
    std::vector<Token*> tokensToParse;

};


#endif //PROJECT_1_PARSER_H
