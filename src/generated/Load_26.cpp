#include "HeavyTemplates.h"
#include <iostream>

void load_heavy_26() {
    // Instantiate heavy templates
    HeavyType<int, 56>::do_something();
    
    volatile unsigned long long f = Factorial<21>::value;
    volatile unsigned long long fib = Fibonacci<21>::value;
    
    // Prevent optimization
    if (f == 0) std::cout << "Impossible" << std::endl;
}
