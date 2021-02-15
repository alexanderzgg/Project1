//
// Created by Alex on 2/8/2021.
//

#include "Parser.h"
//Functions for each non-terminal.

//SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF
void Parser::RunDatalogProgram()
{

//########### Test printing code
//    class Predicate* testing;
//    testing = new class Predicate("snap");
//    class Parameter* param = new class Parameter("S");
//    class Parameter* param2 = new class Parameter("N");
//    class Parameter* param3 = new class Parameter("A");
//    class Parameter* param4 = new class Parameter("P");
//    testing->AddParam(param);
//    testing->AddParam(param2);
//    testing->AddParam(param3);
//    testing->AddParam(param4);
//    mainDatalog.PushSchemes(testing);
//
//
//    class Predicate* testing2;
//    testing2 = new class Predicate("snap");
//    class Parameter* param5 = new class Parameter("'33333'");
//    class Parameter* param6 = new class Parameter("'snoopy'");
//    class Parameter* param7 = new class Parameter("'12 Apple'");
//    class Parameter* param8 = new class Parameter("'555-1234'");
//    testing2->AddParam(param5);
//    testing2->AddParam(param6);
//    testing2->AddParam(param7);
//    testing2->AddParam(param8);
//    mainDatalog.PushSchemes(testing2);
//    std::cout << mainDatalog.ToString() << std::endl;

    counter = 0;
    try {
        Matcher(SCHEMES);
        Matcher(COLON);
        Scheme();
        SchemeList();
        Matcher(FACTS);
        Matcher(COLON);
        FactList();
        Matcher(RULES);
        Matcher(COLON);
        RuleList();
        Matcher(QUERIES);
        Matcher(COLON);
        Query();
        QueryList();
        std::cout << "Success!" << std::endl;
        std::cout << mainDatalog.ToString() << std::endl;
    }
    catch (Token* tok)
    {
        std::cout << "Failure!" << '\n' << "  " << tok->ToString() << std::endl;
    }

}
//scheme schemeList | lambda
void Parser::SchemeList()
{
    //First
    if(Next(ID))
    {
        Scheme();
        SchemeList();
    }
    //Follow set
    else if (Next(FACTS))
    {
        //Do nothing
    }
    //Invalid
    else throw tokensToParse.at(counter);
}
//fact factList | lambda
void Parser::FactList()
{
    //First set
    if(Next(ID))
    {
        Fact();
        FactList();
    }
    //Follow set
    else if(Next(RULES))
    {
        //Do nothing
    }
    else throw tokensToParse.at(counter);
}
//rule ruleList | lambda
void Parser::RuleList()
{
    //First set
    if(Next(ID))
    {
        Rule();
        RuleList();
    }
        //Follow set
    else if(Next(QUERIES))
    {
        //Do nothing
    }
    else throw tokensToParse.at(counter);
}
//query queryList | lambda
void Parser::QueryList()
{
    if(Next(ID))
    {
        Query();
        QueryList();
    }
        //Follow set
    else if(Next(END))
    {
        //Do nothing
    }
    else throw tokensToParse.at(counter);
}
//ID LEFT_PAREN ID idList RIGHT_PAREN
void Parser::Scheme()
{
    //First
    if(Next(ID))
    {
        class Predicate* newScheme = new class Predicate(tokensToParse.at(counter)->tokenValue);
        Matcher(ID);
        Matcher(LEFT_PAREN);
        PlainParam* firstParam = new PlainParam(tokensToParse.at(counter)->tokenValue);
        newScheme->AddParam(firstParam);
        Matcher(ID);
        IDList(newScheme);
        Matcher(RIGHT_PAREN);
        mainDatalog.PushSchemes(newScheme);
    }
    //Else
    else throw tokensToParse.at(counter);

}
//ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
void Parser::Fact()
{
    //First
    if(Next(ID))
    {
        class Predicate* newFact = new class Predicate(tokensToParse.at(counter)->tokenValue);
        Matcher(ID);
        Matcher(LEFT_PAREN);
        PlainParam* firstParam = new PlainParam(tokensToParse.at(counter)->tokenValue);
        newFact->AddParam(firstParam);
        mainDatalog.PushString(tokensToParse.at(counter)->tokenValue);
        Matcher(STRING);
        StringList(newFact);
        Matcher(RIGHT_PAREN);
        Matcher(PERIOD);
        mainDatalog.PushFacts(newFact);
    }
    else throw tokensToParse.at(counter);
}
//headPredicate COLON_DASH predicate predicateList PERIOD
void Parser::Rule()
{
    //First set
    if(Next(ID)) {
        class Rule* newRule = new class Rule(HeadPredicate());
        Matcher(COLON_DASH);
        newRule->AddPredicate(Predicate());
        PredicateList(newRule);
        Matcher(PERIOD);
        mainDatalog.PushRules(newRule);
    }
    else throw tokensToParse.at(counter);
}
//predicate Q_MARK
void Parser::Query()
{
    if(Next(ID))
    {
        mainDatalog.PushQueries(Predicate());
        Matcher(Q_MARK);
    }
    else throw tokensToParse.at(counter);
}
//ID LEFT_PAREN ID idList RIGHT_PAREN
class Predicate* Parser::HeadPredicate()
{
    if(Next(ID))
    {
        class Predicate* newPred = new class Predicate(tokensToParse.at(counter)->tokenValue);
        Matcher(ID);
        Matcher(LEFT_PAREN);
        PlainParam* firstParam = new PlainParam(tokensToParse.at(counter)->tokenValue);
        newPred->AddParam(firstParam);
        Matcher(ID);
        IDList(newPred);
        Matcher(RIGHT_PAREN);
        return newPred;
    }
    else throw tokensToParse.at(counter);
}
//ID LEFT_PAREN parameter parameterList RIGHT_PAREN
class Predicate* Parser::Predicate()
{
//First set
    if(Next(ID))
    {
        class Predicate* newPred = new class Predicate(tokensToParse.at(counter)->tokenValue);
        Matcher(ID);
        Matcher(LEFT_PAREN);
        newPred->AddParam(Parameter());
        ParameterList(newPred);
        Matcher(RIGHT_PAREN);
        return newPred;
    }
    else throw tokensToParse.at(counter);
}
//COMMA predicate predicateList | lambda
void Parser::PredicateList(class Rule* rule)
{
    //First set
    if(Next(COMMA))
    {
        Matcher(COMMA);
        rule->AddPredicate(Predicate());
        PredicateList(rule);
    }
        //Follow set
    else if(Next(PERIOD))
    {
        //Do nothing
    }
    else throw tokensToParse.at(counter);
}
//COMMA parameter parameterList | lambda
void Parser::ParameterList(class Predicate* pred)
{
    //First set
    if(Next(COMMA))
    {
        Matcher(COMMA);
        pred->AddParam(Parameter());
        ParameterList(pred);
    }
        //Follow set
    else if(Next(RIGHT_PAREN))
    {
        //Do nothing
    }
    else throw tokensToParse.at(counter);
}
//COMMA STRING stringList | lambda
void Parser::StringList(class Predicate* pred)
{
    //First
    if(Next(COMMA))
    {
        Matcher(COMMA);
        PlainParam* nextParam = new PlainParam(tokensToParse.at(counter)->tokenValue);
        pred->AddParam(nextParam);
        mainDatalog.PushString(tokensToParse.at(counter)->tokenValue);
        Matcher(STRING);
        StringList(pred);
    }
    //Follow
    else if (Next(RIGHT_PAREN))
    {
        //Do nothing, move on.
    }
    else throw tokensToParse.at(counter);
}
//COMMA ID idList | lambda
void Parser::IDList(class Predicate* pred)
{
    //First
    if(Next(COMMA))
    {
        Matcher(COMMA);
        PlainParam* nextParam = new PlainParam(tokensToParse.at(counter)->tokenValue);
        pred->AddParam(nextParam);
        Matcher(ID);
        IDList(pred);
    }
    //Follow
    else if (Next(RIGHT_PAREN)){
        //Do nothing, just pass.
    }
    else{
        throw tokensToParse.at(counter);
    }


}
//STRING | ID | expression
Parameter* Parser::Parameter()
{
    //First set
    if(Next(STRING))
    {
        PlainParam* nextParam = new PlainParam(tokensToParse.at(counter)->tokenValue);
        Matcher(STRING);
        return nextParam;
    }
    else if(Next(ID))
    {
        PlainParam* nextParam = new PlainParam(tokensToParse.at(counter)->tokenValue);
        Matcher(ID);
        return nextParam;
    }
    else if(Next(LEFT_PAREN))
    {
        return Expression();
    }
    else throw tokensToParse.at(counter);
}

//LEFT_PAREN parameter operator parameter RIGHT_PAREN
class ExpressionParam* Parser::Expression()
{
    if(Next(LEFT_PAREN))
    {
        ExpressionParam* nextParam = new ExpressionParam("Aye");
        Matcher(LEFT_PAREN);
        nextParam->SetLeft(Parameter());
        nextParam->SetOperator(Operator());
        nextParam->SetRight(Parameter());
        Matcher(RIGHT_PAREN);
        return nextParam;
    }
    else throw tokensToParse.at(counter);
}
//ADD | MULTIPLY
class Parameter* Parser::Operator()
{
    if(Next(ADD))
    {
        PlainParam* nextParam = new PlainParam(tokensToParse.at(counter)->tokenValue);
        Matcher(ADD);
        return nextParam;
    }
    else if(Next(MULTIPLY))
    {
        PlainParam* nextParam = new PlainParam(tokensToParse.at(counter)->tokenValue);
        Matcher(MULTIPLY);
        return nextParam;
    }
    else throw tokensToParse.at(counter);
}

//Function that checks a token against a given type to see if it matches
void Parser::Matcher(TokenType tokenType)
{
    if(tokensToParse.at(counter)->getTok() == tokenType)
    {
        counter++;
    } else{
        throw tokensToParse.at(counter);
    }

}

//Function that checks the next token against a given type to see if it matches
bool Parser::Next(TokenType tokenType)
{
    return tokensToParse.at(counter)->getTok() == tokenType;
}