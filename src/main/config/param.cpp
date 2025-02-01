//
// Created by belkadi on 6/25/24.
//

#include "param.h"
int Parameters::Nx = 0;
int Parameters::Ny = 0;

Parameters::Parameters()
        : Lx(0.0), Ly(0.0), dt(0.0), alpha(0.0), beta(0.0), gamma(0.0), dx(0.0), dy(0.0), timeStep(0.0) {}

void Parameters::setParams(double Lx, double Ly, int nx, int ny, double dt, double alpha, double beta, double gamma,int timeStep) {
    this->Lx = Lx;
    this->Ly = Ly;
    Nx = nx;  // Static member variables set here
    Ny = ny;
    this->dt = dt;
    this->alpha = alpha;
    this->beta = beta;
    this->gamma = gamma;
    this->timeStep = timeStep;
    this->dx = Lx / Nx;
    this->dy = Ly / Ny;
}

void Parameters::initializeStaticMembers(int nx, int ny) {
    Nx = nx;
    Ny = ny;
}