//
// Created by belkadi on 6/26/24.
//
#include <vector>
#include <string>
//#include <vtkSmartPointer.h>
//#include <vtkStructuredPoints.h>
//#include <vtkStructuredPointsWriter.h>
#include <vtkNew.h>
#include <vtkPoints.h>
#include <vtkStructuredGrid.h>
#include <vtkXMLStructuredGridWriter.h>


#ifndef CPP_TUTORIAL_PROGRAMMING_VTKWRITER_H
#define CPP_TUTORIAL_PROGRAMMING_VTKWRITER_H

class VTKWriter {
public:
    VTKWriter(const std::vector<std::vector<double>> &field, int Nx, int Ny, double dx, double dy);

    void writeToFile(const std::string &filename);

private:
    const std::vector<std::vector<double>> &field;
    int Nx;
    int Ny;
    double dx;
    double dy;
};

#endif
