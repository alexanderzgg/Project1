//
// Created by Alex on 2/13/2021.
//

#include "Rule.h"
std::string Rule::ToString()
{
    std::string toReturn;
    toReturn.append(headPredicate->ToString());
    toReturn.append(" :- ");
    for(unsigned i = 0; i < predList.size(); i++)
    {
        toReturn.append(predList.at(i)->ToString());
        if(i < predList.size()-1)
        {
            toReturn.push_back(',');
        }
    }
    return toReturn;
}
void Rule::AddPredicate(Predicate* predToAdd)
{
    predList.push_back(predToAdd);
}