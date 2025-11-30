# C++ Docker CI/CD Benchmark

A complex C++ project demonstrating heavy builds with CMake, Docker, and CI/CD integration.

## Project Architecture

This project features a multi-library architecture to demonstrate complex linking:

- **HeavyCore** (Static Library): Contains heavy template metaprogramming code with 50+ generated source files
- **HeavyUtils** (Shared Library): Provides logging and versioning utilities
- **MathLib** (Shared Library): Mathematical computation functions
- **HeavyBuildCpp** (Executable): Main application linking all libraries

## Dependencies

External dependencies managed via CMake FetchContent:
- `fmt` - Text formatting library
- `spdlog` - Fast logging library
- `nlohmann_json` - JSON parsing library

## Build Instructions

### Using Make (Recommended)

```bash
# Build development image
make build

# Build production image
make build-prod

# Push to DockerHub
make push
make push-prod
```

### Using Docker Directly

```bash
# Build
sudo docker build -t cpp-heavy-build .

# Run
sudo docker run --rm cpp-heavy-build
```

### Local Build (without Docker)

```bash
# Configure
cmake -S . -B build

# Build with parallel compilation
cmake --build build --parallel $(nproc)

# Run
./build/HeavyBuildCpp
```

## Project Structure

```
cpp-docker-cicd-benchmark/
├── CMakeLists.txt          # CMake configuration
├── Dockerfile              # Docker build configuration
├── Makefile                # Build automation
├── src/
│   ├── main.cpp            # Application entry point
│   ├── Heavy.cpp           # Heavy computation logic
│   ├── Utils.cpp/h         # Shared library (logging/versioning)
│   ├── MathLib.cpp/h       # Shared library (math functions)
│   └── generated/          # 50+ auto-generated heavy template files
└── jenkins/
    └── Jenkinsfile         # CI/CD pipeline configuration
```

## Features

- **Heavy Build**: Compiles 50+ template-heavy C++ files to stress-test build systems
- **Mixed Linking**: Demonstrates both static and shared library linking
- **Parallel Compilation**: Utilizes all available CPU cores
- **Docker Optimization**: Multi-stage build with position-independent code
- **CI/CD Ready**: Jenkins pipeline configuration included

## Requirements

- Docker
- CMake 3.14+
- C++17 compatible compiler
- Git

## CI/CD

The project includes a Jenkinsfile for automated builds and deployments. Configure your Jenkins instance with DockerHub credentials.

## License

See LICENSE file for details.
