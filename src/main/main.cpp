#include <iostream>
#include "config/param.h"
#include "derivatives/derivative.h"
#include "fields/fields.h"
#include "solver/Algorithm.h"
#include "newtonImpl/newton.h"
#include "utils/utils.hpp"
#include "streamfile/vtkWriter.h"
#include <numbers>
//#include "third_party/eigen-3.4.0/Eigen/Dense"



int main(int argc, char* argv[]) {
    Parameters params;
    //Parse command-line arguments
    double Lx = std::atof(argv[1]);
    double Ly = std::atof(argv[2]);
    int Nx = std::atoi(argv[3]);
    int Ny = std::atoi(argv[4]);
    double dt = std::atof(argv[5]);
    double alpha = std::atof(argv[6]);
    double beta = std::atof(argv[7]);
    double gamma = std::atof(argv[8]);
    double timeStep = std::atof(argv[9]);
    params.setParams(Lx, Ly, Nx, Ny, dt, alpha, beta, gamma, timeStep);

    Fields fields(params);
    Algorithm algorithm(params);
    Newton newton(params);
    //newton.newtonSolver(fields.Uk, fields.Ukp, fields.qdotSource);
    VTKWriter vtkWriter(fields.Uk, Parameters::Nx, Parameters::Ny, params.dx, params.dy);
    double errorValues[params.timeStep-1];
    double itterationValues[params.timeStep-1];
    int start = 0;
    for (int i = start; i <= params.timeStep; i++) {
        std::cout << "Time step number: " << i << std::endl;
        if (i==0) {
            std::cout << "set initial conditions" <<std::endl;
            fields.setInitialCond(fields.Uk);

            displayField(fields.Uk, "Uk");
            vtkWriter.writeToFile(std::to_string(i) + ".vts");
        }
        else if ( i>0 ) {
            fields.setSourceTerm(i, fields.qdotSource, fields.Ukp);
            itterationValues[i]= newton.newtonSolver(fields.Uk, fields.Ukp, fields.qdotSource);
            for (int i = 0; i < params.Nx; i++) {
                for (int j = 0; j < params.Ny; j++) {
                    fields.Uk[i][j]=fields.Ukp[i][j];
                }
            }
            displayField(fields.Uk, "Uk");
            vtkWriter.writeToFile(std::to_string(i) + ".vts");
            if (params.beta==0){
            fields.setAnalyticalSolution(i, fields.fieldAnalyticalSolution);
            errorValues[i]=fields.computeL2Error(fields.Uk,fields.fieldAnalyticalSolution);

            }

        }


    }
    writeOutputToFiles(errorValues,params.timeStep,"outputErorr.txt");
    writeOutputToFiles(itterationValues,params.timeStep,"itterations.txt");

    return 0;

}
