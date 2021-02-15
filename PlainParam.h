//
// Created by Alex on 2/14/2021.
//

#ifndef PROJECT_1_PLAINPARAM_H
#define PROJECT_1_PLAINPARAM_H

#include "Parameter.h"

class PlainParam :
        public Parameter
{
public:
    PlainParam(std::string data) : Parameter(data) {
        paramData = data;
    }
    std::string ToString();
private:

};


#endif //PROJECT_1_PLAINPARAM_H
