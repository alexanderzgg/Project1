//
// Created by Alex on 2/13/2021.
//

#ifndef PROJECT_1_PARAMETER_H
#define PROJECT_1_PARAMETER_H

#include <string>
#include <vector>

class Parameter {
protected:

public:
    Parameter(std::string data) {
        paramData = data;
    }
    std::string paramData;
    virtual std::string ToString() = 0;
    void SetData(std::string data){ paramData = data;}

};


#endif //PROJECT_1_PARAMETER_H
