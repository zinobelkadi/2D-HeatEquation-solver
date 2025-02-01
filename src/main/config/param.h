//
// Created by belkadi on 6/25/24.
//
#include <iostream>
#ifndef CPP_TUTORIAL_PROGRAMMING_PARAM_H
#define CPP_TUTORIAL_PROGRAMMING_PARAM_H
    class Parameters {
    public:
        double Lx;
        double Ly;
        static int Nx;
        static int Ny;
        double dt;
        double alpha;
        double beta;
        double gamma;
        int timeStep;
        double dx;
        double dy;

        // Constructor to initialize non-static parameters
        Parameters();

        // Method to set parameters
        void setParams(double Lx, double Ly, int nx, int ny, double dt, double alpha, double beta, double gamma,int timeStep);


        // Static member initialization
        static void initializeStaticMembers(int nx, int ny);
    };


#endif //CPP_TUTORIAL_PROGRAMMING_PARAM_H
