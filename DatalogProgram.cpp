//
// Created by Alex on 2/13/2021.
//

#include "DatalogProgram.h"
std::string DatalogProgram::ToString()
{
    //String to contain output text
    std::string toReturn;

    //Adding schemes
    toReturn.append("Schemes(");
    toReturn.append(std::to_string(schemes.size()));
    toReturn.push_back( ')');
    toReturn.push_back( ':');
    toReturn.push_back( '\n');
    for(auto & scheme : schemes)
    {
        toReturn.append("  ");
        toReturn.append(scheme->ToString());
        toReturn.push_back('\n');
    }

    //Adding facts
    toReturn.append("Facts(");
    toReturn.append(std::to_string(facts.size()));
    toReturn.push_back( ')');
    toReturn.push_back( ':');
    toReturn.push_back( '\n');
    for(auto & fact : facts)
    {
        toReturn.append("  ");
        toReturn.append(fact->ToString());
        toReturn.push_back( '.');
        toReturn.push_back('\n');
    }

    //Adding Rules
    toReturn.append("Rules(");
    toReturn.append(std::to_string(rules.size()));
    toReturn.push_back( ')');
    toReturn.push_back( ':');
    toReturn.push_back( '\n');
    for(auto & Rule : rules)
    {
        toReturn.append("  ");
        toReturn.append(Rule->ToString());
        toReturn.push_back( '.');
        toReturn.push_back('\n');
    }

    //Adding queries
    toReturn.append("Queries(");
    toReturn.append(std::to_string(queries.size()));
    toReturn.push_back( ')');
    toReturn.push_back( ':');
    toReturn.push_back( '\n');
    for(auto & query : queries)
    {
        toReturn.append("  ");
        toReturn.append(query->ToString());
        toReturn.push_back( '?');
        toReturn.push_back('\n');
    }

    //Adding domain values
    toReturn.append("Domain(");
    toReturn.append(std::to_string(stringsInDomain.size()));
    toReturn.push_back( ')');
    toReturn.push_back( ':');
    toReturn.push_back( '\n');
    for(auto & string : stringsInDomain)
    {
        toReturn.append("  ");
        toReturn.append(string);
        toReturn.push_back('\n');
    }

    return toReturn;
}
std::vector<Predicate*> DatalogProgram::GetSchemes()
{
    return schemes;
}
std::vector<Predicate*> DatalogProgram::GetFacts()
{
    return facts;
}
std::vector<Predicate*> DatalogProgram::GetQueries()
{
    return queries;
}
std::vector<Rule*> DatalogProgram::GetRules()
{
    return rules;
}
void DatalogProgram::PushSchemes(Predicate* predToPush)
{
    schemes.push_back(predToPush);
}
void DatalogProgram::PushFacts(Predicate* predToPush)
{
    facts.push_back(predToPush);
}
void DatalogProgram::PushQueries(Predicate* predToPush)
{
    queries.push_back(predToPush);
}
void DatalogProgram::PushRules(Rule* ruleToPush)
{
    rules.push_back(ruleToPush);
}
void DatalogProgram::PushString(std::string stringToPush)
{
    stringsInDomain.insert(stringToPush);
}