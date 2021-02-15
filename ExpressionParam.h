//
// Created by Alex on 2/14/2021.
//

#ifndef PROJECT_1_EXPRESSIONPARAM_H
#define PROJECT_1_EXPRESSIONPARAM_H


#include "Parameter.h"
#include "PlainParam.h"

class ExpressionParam :
        public Parameter {
private:
    Parameter* left;
    Parameter* right;
    Parameter* op;

public:
    ExpressionParam(std::string data) : Parameter(data) {
        left = new PlainParam(data);
        right = new PlainParam("blank");
        op = new PlainParam("blank");
    }
    std::string ToString() override;
    void SetLeft(Parameter* data);
    void SetRight(Parameter* data);
    void SetOperator(Parameter* data);
};
#endif //PROJECT_1_EXPRESSIONPARAM_H
