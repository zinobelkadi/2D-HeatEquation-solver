//
// Created by belkadi on 6/26/24.
//

#include "vtkWriter.h"
#include <vtkNew.h>
#include <vtkPoints.h>
#include <vtkStructuredGrid.h>
#include <vtkXMLStructuredGridWriter.h>
#include <iostream>

VTKWriter::VTKWriter(const std::vector<std::vector<double>>& field, int Nx, int Ny, double dx, double dy)
        : field(field), Nx(Nx), Ny(Ny), dx(dx), dy(dy) {}

void VTKWriter::writeToFile(const std::string& filename) {

    vtkNew<vtkStructuredGrid> structuredGrid;
    vtkNew<vtkPoints> points;

    for (int i = 0; i < Nx; ++i) {
        for (int j = 0; j < Ny; ++j) {
            points->InsertNextPoint(i, j, field[i][j]);
        }
    }
    structuredGrid->SetDimensions(Nx, Ny, 1);
    structuredGrid->SetPoints(points);
    vtkNew<vtkXMLStructuredGridWriter> writer;
    writer->SetFileName(filename.c_str());
    writer->SetInputData(structuredGrid);
    writer->Write();
    std::cout << "vtkfile created " << std::endl;
}