//
// Created by Alex on 2/13/2021.
//

#ifndef PROJECT_1_RULE_H
#define PROJECT_1_RULE_H

#include "Predicate.h"
#include <vector>

class Rule {
public:
    explicit Rule(Predicate* headPred)
    {
        headPredicate = headPred;
    }
    std::string  ToString();
    void AddPredicate(Predicate* predToAdd);
private:
    Predicate* headPredicate;
    std::vector<Predicate*> predList;
};


#endif //PROJECT_1_RULE_H
