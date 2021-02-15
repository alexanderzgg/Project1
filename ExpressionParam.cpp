//
// Created by Alex on 2/14/2021.
//

#include "ExpressionParam.h"
std::string ExpressionParam::ToString()
{
    std::string toReturn;
    toReturn.push_back('(');
    toReturn.append(left->ToString());
    toReturn.append(op->ToString());
    toReturn.append(right->ToString());
    toReturn.push_back(')');
    return toReturn;
}
void ExpressionParam::SetLeft(Parameter* data)
{
    left = data;
}
void ExpressionParam::SetRight(Parameter* data)
{
    right = data;
}
void ExpressionParam::SetOperator(Parameter* data)
{
    op = data;
}