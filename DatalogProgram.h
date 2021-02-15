//
// Created by Alex on 2/13/2021.
//

#ifndef PROJECT_1_DATALOGPROGRAM_H
#define PROJECT_1_DATALOGPROGRAM_H

#include "Predicate.h"
#include "Parameter.h"
#include "Rule.h"
#include <vector>
#include <string>
#include <iostream>
#include <set>

class DatalogProgram {

public:
    DatalogProgram()
    {

    }
    std::string ToString();
    std::vector<Predicate*> GetSchemes();
    std::vector<Predicate*> GetFacts();
    std::vector<Predicate*> GetQueries();
    std::vector<Rule*> GetRules();
    void PushSchemes(Predicate* predToPush);
    void PushFacts(Predicate* predToPush);
    void PushQueries(Predicate* predToPush);
    void PushRules(Rule* ruleToPush);
    void PushString(std::string stringToPush);

private:
    std::vector<Predicate*> schemes;
    std::vector<Predicate*> facts;
    std::vector<Predicate*> queries;
    std::vector<Rule*> rules;
    std::set<std::string> stringsInDomain;

};


#endif //PROJECT_1_DATALOGPROGRAM_H
