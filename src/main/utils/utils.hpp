//
// Created by belkadi on 6/30/24.
//

#include <cmath>
#include <iostream>
#include "string"
#include <fstream>
#pragma once
inline auto sinSquare(auto x)
{
 return std::sin(x)*std::sin(x);


}
inline auto cosSquare(auto x)
{
    return std::cos(x)*std::cos(x);

}

inline auto sinXcos(auto x)
{
    return std::sin(x)*std::cos(x);
}

inline auto cosSqrMinSinSqr(auto x)
{
    return cosSquare(x)- sinSquare(x);
}


template <typename T>
inline void displayField(const T& field, const std::string& fieldName = "Unnamed Field") {
    std::cout << "Field: " << fieldName << std::endl;

    if (field.empty()) {
        std::cout << "Empty field" << std::endl;
        std::cout << std::endl;
        return;
    }

    size_t rows = field.size();
    size_t cols = field[0].size();

    std::cout << "Dimensions: " << rows << " x " << cols << std::endl;

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

inline void writeOutputToFiles(const double Values[],  int size, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::app); // Open in append mode

    if (outFile.is_open()) {
        for (int i = 0; i < size; ++i) {
            outFile << i << "\t" << i << "\t" << Values[i] << std::endl;
        }
        outFile.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}