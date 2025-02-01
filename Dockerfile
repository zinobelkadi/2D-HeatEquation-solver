FROM ubuntu:latest

# Set non-interactive mode for apt-get
ENV DEBIAN_FRONTEND=noninteractive

# Update and install dependencies
RUN apt-get update -y \
    && apt-get install -y --no-install-recommends \
    wget \
    build-essential \
    cmake \
    libeigen3-dev \
    libgl1-mesa-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /tmp
# Download and install VTK (if required)
RUN wget --no-check-certificate https://www.vtk.org/files/release/9.3/VTK-9.3.0.tar.gz && \
    tar xf VTK-9.3.0.tar.gz && \
    cd VTK-9.3.0 && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make -j$(nproc) && \
    make install && \
    cd /tmp && \
    rm -rf VTK-9.3.0 VTK-9.3.0.tar.gz

#ENV VTK_DIR=/usr/local/lib/cmake/vtk-9.3

# Set working directory for the application
WORKDIR /app

# Set VTK_DIR environment variable (adjust path if needed)

# Copy application source code, script, and CMakeLists.txt
COPY src/ /app/src/
COPY runSolver.sh /app/
COPY CMakeLists.txt /app/


# Run the application
CMD ["bash","./runSolver.sh"]
