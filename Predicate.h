//
// Created by Alex on 2/13/2021.
//

#ifndef PROJECT_1_PREDICATE_H
#define PROJECT_1_PREDICATE_H

#include "Token.h"
#include "Parameter.h"
#include <vector>

    class Predicate {
    public:
        Predicate(std::string sName)
        {
            name = sName;
        }
        std::vector<Parameter*> GetParams();
        std::string ToString();
        void AddParam(Parameter* param);
        void SetName(std::string sName);
    private:
        std::string name;
        std::vector<Parameter*> paramList;
};


#endif //PROJECT_1_PREDICATE_H
