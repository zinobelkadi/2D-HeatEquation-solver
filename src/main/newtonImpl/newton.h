//
// Created by belkadi on 6/26/24.
//
#include "../solver/Algorithm.h"
#include "Eigen/Dense"
#include "../fields/fields.h"
#include <vector>
#ifndef CPP_TUTORIAL_PROGRAMMING_NEWTON_H
#define CPP_TUTORIAL_PROGRAMMING_NEWTON_H


class Newton {
public:
    Newton(const Parameters& params);


void updater(std::vector<std::vector<double>>& fieldNew, Eigen::VectorXd& solutionVector);
int newtonSolver(std::vector<std::vector<double>>& field,std::vector<std::vector<double>>& fieldNew,std::vector<std::vector<double>>& sourceTerm);

private:
    Parameters params;
};


#endif //CPP_TUTORIAL_PROGRAMMING_NEWTON_H
