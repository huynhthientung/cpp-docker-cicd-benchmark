#include "HeavyTemplates.h"
#include <iostream>

void load_heavy_45() {
    // Instantiate heavy templates
    HeavyType<int, 55>::do_something();
    
    volatile unsigned long long f = Factorial<20>::value;
    volatile unsigned long long fib = Fibonacci<20>::value;
    
    // Prevent optimization
    if (f == 0) std::cout << "Impossible" << std::endl;
}
