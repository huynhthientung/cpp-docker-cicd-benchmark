FROM ubuntu:22.04

# Avoid interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy project files
COPY . .

# Configure CMake
RUN cmake -S . -B build

# Build with maximum parallelism
# $(nproc) returns the number of processing units available
RUN echo "Building with $(nproc) cores..." && \
    cmake --build build --parallel $(nproc)

# Default command
CMD ["./build/HeavyBuildCpp"]
