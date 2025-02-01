//
// Created by belkadi on 6/7/24.
//
#include "../fields/fields.h"
#include <vector>


#ifndef CPP_TUTORIAL_PROGRAMMING_DERIVATIVE_H
#define CPP_TUTORIAL_PROGRAMMING_DERIVATIVE_H
class LaplacianCalculator {
public:
    LaplacianCalculator(const Parameters& params);

    double laplacianOperator(int i, int j, std::vector<std::vector<double>>& field);

private:
    Parameters params;
};








#endif //CPP_TUTORIAL_PROGRAMMING_DERIVATIVE_H
