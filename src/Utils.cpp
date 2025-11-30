#include "Utils.h"
#include <iostream>
#include <spdlog/spdlog.h>

namespace Utils {
    void log_message(const std::string& msg) {
        spdlog::info("[Utils Shared Lib] {}", msg);
    }

    std::string get_version() {
        return "1.0.0-Heavy";
    }
}
