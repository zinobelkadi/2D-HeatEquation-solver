# 2D implicit Heat equation solver 



# Project Title

## Project Structure

Here is my project structure:
├── CMakeLists.txt
├── Dockerfile
├── runSolver.sh
└── src
    └── main
        ├── config
        │   ├── param.cpp
        │   └── param.h
        ├── derivatives
        │   ├── derivative.cpp
        │   └── derivative.h
        ├── fields
        │   ├── fields.cpp
        │   └── fields.h
        ├── main.cpp
        ├── newtonImpl
        │   ├── newton.cpp
        │   └── newton.h
        ├── solver
        │   ├── Algorithm.cpp
        │   └── Algorithm.h
        ├── streamfile
        │   ├── vtkWriter.cpp
        │   └── vtkWriter.h
        ├── third_party
        │   └── eigen-3.4.0
        └── utils
            └── utils.hpp


## Running the Solver

You can run the solver with the following command:

```sh
./runSolver.sh
```

If needed, you can provide additional arguments:

    Lx
    Ly
    Nx
    Ny
    dt
    alpha
    beta
    gamma
    timeStep

Example usage with arguments:
```
./runSolver.sh 1 1 16 16 0.001 1 1 1 100
```