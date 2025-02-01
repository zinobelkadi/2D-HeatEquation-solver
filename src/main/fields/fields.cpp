//
// Created by belkadi on 6/7/24.
//
#include "fields.h"



Fields::Fields(const Parameters& params) : params(params) {
    Uk.resize(Parameters::Nx, std::vector<double>(Parameters::Ny, 0.0));
    Ukp.resize(Parameters::Nx, std::vector<double>(Parameters::Ny, 0.0));
    qdotSource.resize(Parameters::Nx, std::vector<double>(Parameters::Ny, 0.0));
    fieldAnalyticalSolution.resize(Parameters::Nx, std::vector<double>(Parameters::Ny, 0.0));

}

void Fields::setDirichlet(std::vector<std::vector<double>> &field) {

    for (int j = 0; j < params.Ny; ++j) {
        field[0][j] = 0.0;
        field[params.Nx-1][j] = 0.0;
    }

    for (int i = 0; i < params.Nx; ++i) {
        field[i][0] = 0.0;
        field[i][params.Ny-1] = 0.0;
    }

}

void Fields::setInitialCond(std::vector<std::vector<double>>& field){
    double Pi= 3.14159265359;
    int i,j;
    for (i = 0; i < params.Nx; i++) {
        for (j = 0; j < params.Ny ; j++) {
            field[i][j]= sin(i*params.dx*Pi)*sin(i*params.dx*Pi)*sin(j*params.dy*Pi)*sin(j*params.dx*Pi);

        }
    }
    Fields::setDirichlet(field);
}


void Fields::setSourceTerm(int t ,std::vector<std::vector<double>> &field, std::vector<std::vector<double>>& uField) {
    double Pi= 3.14159265359;
    t= t+1;
    int i,j;

    for (i = 0; i < params.Nx; i++) {
        for (j = 0; j < params.Ny; j++) {
            double piX= params.dx*i*Pi;
            double piY= params.dy*j*Pi;
            double gammaTimePiTimet= t*params.dt*params.gamma*Pi;


            field[i][j] = -2*Pi* sinSquare(piX) * sinSquare(piY)* sinXcos(gammaTimePiTimet)
                    -2*params.alpha*Pi*cosSqrMinSinSqr(piX)* sinSquare(piY)* cosSquare(gammaTimePiTimet)
                    -2*params.alpha*Pi*cosSqrMinSinSqr(piY)*sinSquare(piX)*cosSquare(gammaTimePiTimet)
                    -params.beta*std::pow(uField[i][j], 4);

        }
        Fields::setDirichlet(field);

    }
}

void Fields::setAnalyticalSolution(int t, std::vector<std::vector<double>> &field) {
    int i,j;
    double Pi=3.14159265359;
    for (i = 0; i < params.Nx; i++) {
        for (j = 0; j < params.Ny; j++) {
            double piX = params.dx * i * Pi;
            double piY = params.dy * j * Pi;
            double gammaTimePiTimet = t * params.dt * params.gamma * Pi;
            field[i][j] = sinSquare(piX) * sinSquare(piY ) * cosSquare(gammaTimePiTimet);
        } }

}


double  Fields::computeL2Error(std::vector<std::vector<double>> &uField,
                            std::vector<std::vector<double>> &analyticalSolution) {
int i,j;
double error=0;
    for (i = 0; i < params.Nx; i++) {
        for (j = 0; j < params.Ny; j++) {
            error += std::pow(uField[i][j]-analyticalSolution[i][j],2);
        }
    }
    return error;
}

