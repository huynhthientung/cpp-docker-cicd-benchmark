#include "MathLib.h"
#include <cmath>

namespace MathLib {
    double complex_calculation(double a, double b) {
        return std::sqrt(std::pow(a, 2) + std::pow(b, 2));
    }
}
