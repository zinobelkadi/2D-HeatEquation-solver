//
// Created by belkadi on 6/7/24.
//

#include "derivative.h"
LaplacianCalculator::LaplacianCalculator(const Parameters& params) : params(params) {}

// Method to calculate the Laplacian at a specific point (i, j)
double LaplacianCalculator::laplacianOperator(int i, int j, std::vector<std::vector<double>>& field) {
    double laplacian;
    if (i == 0 || i ==  params.Nx || j == 0 || j == params.Ny) {
        return 0; //
    }
    else { double laplacian = params.alpha * ((field[i + 1][j] + field[i - 1][j] - 2.0 * field[i][j]) / (params.dx * params.dx)) +
                              params.alpha * ((field[i][j + 1] + field[i][j - 1] - 2.0 * field[i][j]) / (params.dy * params.dy));

        return laplacian;
    }

}