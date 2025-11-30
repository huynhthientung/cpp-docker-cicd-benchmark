cmake_minimum_required(VERSION 3.14)
project(HeavyBuildCpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


include(FetchContent)

# Dependency: fmt
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG        10.1.1
)
FetchContent_MakeAvailable(fmt)

# Dependency: spdlog
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG        v1.12.0
)
FetchContent_MakeAvailable(spdlog)

# Dependency: nlohmann_json
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG        v3.11.2
)
FetchContent_MakeAvailable(json)

# --- Library Definitions ---

# 1. Shared Library: HeavyUtils
add_library(HeavyUtils SHARED src/Utils.cpp)
target_link_libraries(HeavyUtils PRIVATE spdlog::spdlog)
target_include_directories(HeavyUtils PUBLIC src)

# 2. Shared Library: MathLib
add_library(MathLib SHARED src/MathLib.cpp)
target_include_directories(MathLib PUBLIC src)

# 3. Static Library: HeavyCore (contains generated heavy code)
file(GLOB GENERATED_SOURCES "src/generated/*.cpp")
add_library(HeavyCore STATIC src/Heavy.cpp ${GENERATED_SOURCES})
target_include_directories(HeavyCore PUBLIC src/generated)

# --- Main Executable ---

add_executable(HeavyBuildCpp src/main.cpp)
target_link_libraries(HeavyBuildCpp 
    PRIVATE 
    HeavyUtils 
    MathLib 
    HeavyCore
    fmt::fmt 
    spdlog::spdlog 
    nlohmann_json::nlohmann_json
)
