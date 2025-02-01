//
// Created by belkadi on 6/26/24.
//

#include "newton.h"
Newton::Newton(const Parameters& params) : params(params) {}



void Newton::updater(std::vector<std::vector<double>>& fieldNew, Eigen::VectorXd& solutionVector ) {
    for (int i = 0; i < params.Nx; i++) {
        for (int j = 0; j < params.Ny; j++) {
            int k = i * params.Nx + j;
            fieldNew[i][j] += solutionVector(k);
        }

    }
}



int Newton::newtonSolver(std::vector<std::vector<double>>& field, std::vector<std::vector<double>>& fieldNew, std::vector<std::vector<double>>& sourceTerm) {
    const int iteration_max = 100;
    const double tolerance = 0.0001;
    int iterationCount= 0;
    Algorithm algorithm(params);
    Fields fields(params);
    Eigen::VectorXd solutionVector = Eigen::VectorXd::Zero(Parameters::Nx * Parameters::Ny);
    for (int iteration = 0; iteration < iteration_max; ++iteration) {
        std::cout << "Iteration number: " << iteration << std::endl;
        Eigen::MatrixXd jacobiMatrix = algorithm.evaluateJacobi(field);
        Eigen::VectorXd G = algorithm.computeG(field, fieldNew, sourceTerm);
        solutionVector = jacobiMatrix.colPivHouseholderQr().solve(-G);
        updater(fieldNew, solutionVector);
        fields.setDirichlet(fieldNew);

        if (solutionVector.norm() < tolerance) {
                std::cout << "Converged after " << iteration << " iterations.\n";
                iterationCount = iteration;
                break;

        }

        }
    return iterationCount;
    }

