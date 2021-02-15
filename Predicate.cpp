//
// Created by Alex on 2/13/2021.
//

#include "Predicate.h"

std::vector<Parameter*> Predicate::GetParams()
{
    return paramList;
}
std::string Predicate::ToString()
{
    std::string strToSend;
    strToSend.append(name + '(');
    for(unsigned i = 0; i < paramList.size(); i++)
    {
        strToSend.append(paramList.at(i)->ToString());
        if(i < paramList.size()-1)
        {
            strToSend.push_back(',');
        }
    }
    strToSend.push_back(')');
    return strToSend;
}
void Predicate::SetName(std::string sName)
{
    name = sName;
}
void Predicate::AddParam(Parameter* param)
{
    paramList.push_back(param);
}

