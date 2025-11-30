#include "HeavyTemplates.h"
#include <iostream>

void load_heavy_44() {
    // Instantiate heavy templates
    HeavyType<int, 54>::do_something();
    
    volatile unsigned long long f = Factorial<24>::value;
    volatile unsigned long long fib = Fibonacci<24>::value;
    
    // Prevent optimization
    if (f == 0) std::cout << "Impossible" << std::endl;
}
