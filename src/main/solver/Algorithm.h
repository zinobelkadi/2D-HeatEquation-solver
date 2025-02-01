//
// Created by belkadi on 6/26/24.
//
#include "../config/param.h"
#include "../fields/fields.h"
#include "Eigen/Dense"
#include "../derivatives/derivative.h"
#ifndef CPP_TUTORIAL_PROGRAMMING_ALGORITHM_H
#define CPP_TUTORIAL_PROGRAMMING_ALGORITHM_H

class Algorithm {
public:
    Algorithm(const Parameters& params);

    // Method to evaluate the Jacobi matrix

    Eigen::MatrixXd evaluateJacobi(const std::vector<std::vector<double>>& field);
    Eigen::VectorXd computeG(std::vector<std::vector<double>>& field, std::vector<std::vector<double>>& fieldNew, std::vector<std::vector<double>>& sourceTerm);
private:
    Parameters params;
};



#endif //CPP_TUTORIAL_PROGRAMMING_ALGORITHM_H
