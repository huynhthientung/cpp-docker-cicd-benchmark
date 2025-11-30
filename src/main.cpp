#include <iostream>
#include <vector>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <fmt/core.h>

#include "Utils.h"
#include "MathLib.h"

// Forward declaration from HeavyCore
void run_heavy_computation();

int main() {
    Utils::log_message("Starting Heavy Build Application");
    Utils::log_message(fmt::format("Version: {}", Utils::get_version()));

    nlohmann::json j;
    j["app"] = "HeavyBuildCpp";
    j["version"] = Utils::get_version();
    
    std::cout << fmt::format("JSON Config: {}", j.dump(4)) << std::endl;

    double result = MathLib::complex_calculation(3.0, 4.0);
    Utils::log_message(fmt::format("MathLib Calculation (3,4): {}", result));

    Utils::log_message("Running heavy computation from Static Lib...");
    run_heavy_computation();
    Utils::log_message("Heavy computation finished.");

    return 0;
}
