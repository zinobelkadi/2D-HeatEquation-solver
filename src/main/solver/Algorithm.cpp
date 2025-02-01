//
// Created by belkadi on 6/26/24.
//

#include "Algorithm.h"
Algorithm::Algorithm(const Parameters& params) : params(params) {}

Eigen::MatrixXd Algorithm::evaluateJacobi( const std::vector<std::vector<double>>& field) {

    int Nx = Parameters::Nx;
    int Ny = Parameters::Ny;
    int size = Nx * Ny;
    Eigen::MatrixXd jacobiMatrix(size, size);
    jacobiMatrix.setZero();
    double C = (params.dt * params.alpha) / (params.dx * params.dx);

    for (int i = 0; i < Nx; ++i) {
        for (int j = 0; j < Ny; ++j) {
            int k = i * Nx + j;
            jacobiMatrix(k, k) = 1 + 4 * C + 4 * params.dt * params.beta * field[i][j]*field[i][j]*field[i][j];
             if (j < Nx - 1)  {
                jacobiMatrix(k, k+1) = -C;
            } else if (j > 0 )   {
                jacobiMatrix(k, k-1) = -C;
            } else if (i < Nx-1 ) {
                jacobiMatrix(k, k+Nx) = -C;
            }
            else if ( i >0  ) {
                jacobiMatrix(k, k-Nx) = -C;
            }
        }
    }

    return jacobiMatrix;
}




Eigen::VectorXd Algorithm::computeG(std::vector<std::vector<double>>& field, std::vector<std::vector<double>>& fieldNew, std::vector<std::vector<double>>& sourceTerm){
    LaplacianCalculator laplacianCalculator(params);
    Fields fields(params);
    int Nx = Parameters::Nx;
    int Ny = Parameters::Ny;
    int size = Nx * Ny;
    Eigen::VectorXd G = Eigen::VectorXd::Zero(size);
    double C = (params.dt * params.alpha) / (params.dx * params.dx);
    for (int i = 0; i < params.Nx-1; i++) {
            for (int j = 0; j < params.Ny - 1; j++) {
                int k= i *Nx +j;
                G(k)= fieldNew[i][j] -field[i][j]  -params.dt*laplacianCalculator.laplacianOperator(i,j,fieldNew) +params.dt*sourceTerm[i][j];
            }}
    return G;
            }

