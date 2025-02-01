//
// Created by belkadi on 6/7/24.
//
#include "../config/param.h"
#include <vector>
#include <cmath>
#include "../utils/utils.hpp"
#ifndef CPP_TUTORIAL_PROGRAMMING_GRID_H
#define CPP_TUTORIAL_PROGRAMMING_GRID_H
class Fields {
    public:
    std::vector<std::vector<double>> Uk;
    std::vector<std::vector<double>> Ukp;
    std::vector<std::vector<double>> qdotSource;
    std::vector<std::vector<double>> fieldAnalyticalSolution;




    Fields(const Parameters& params);


    void setDirichlet(std::vector<std::vector<double>>& field);
    void setInitialCond( std::vector<std::vector<double>>& field);
    void setSourceTerm( int t ,std::vector<std::vector<double>>& field, std::vector<std::vector<double>>& uField);
    void setAnalyticalSolution(int t, std::vector<std::vector<double>>& field);
    double computeL2Error(std::vector<std::vector<double>>& uField , std::vector<std::vector<double>>& analyticalSolution);

private:
    Parameters params;
};

#endif //CPP_TUTORIAL_PROGRAMMING_GRID_H
