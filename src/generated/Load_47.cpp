#include "HeavyTemplates.h"
#include <iostream>

void load_heavy_47() {
    // Instantiate heavy templates
    HeavyType<int, 57>::do_something();
    
    volatile unsigned long long f = Factorial<22>::value;
    volatile unsigned long long fib = Fibonacci<22>::value;
    
    // Prevent optimization
    if (f == 0) std::cout << "Impossible" << std::endl;
}
