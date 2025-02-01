#!/bin/bash


DEFAULT_Lx=1.0
DEFAULT_Ly=1.0
DEFAULT_Nx=10
DEFAULT_Ny=10
DEFAULT_dt=0.001
DEFAULT_alpha=0.1
DEFAULT_beta=0
DEFAULT_gamma=0.3
DEFAULT_timestep=30


Lx=${1:-$DEFAULT_Lx}
Ly=${2:-$DEFAULT_Ly}
Nx=${3:-$DEFAULT_Nx}
Ny=${4:-$DEFAULT_Ny}
dt=${5:-$DEFAULT_dt}
alpha=${6:-$DEFAULT_alpha}
beta=${7:-$DEFAULT_beta}
gamma=${8:-$DEFAULT_gamma}
timestep=${9:-$DEFAULT_timestep}


# Build the project using CMake
mkdir -p build
cd build
cmake ..
make

echo "Waiting for file to be ready..."
sleep 5

# Run the program with the provided arguments
./CPP_tutorial_programming $Lx $Ly $Nx $Ny $dt $alpha $beta $gamma $timestep