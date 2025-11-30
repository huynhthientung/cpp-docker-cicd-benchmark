#include "HeavyTemplates.h"
#include <iostream>

void load_heavy_38() {
    // Instantiate heavy templates
    HeavyType<int, 58>::do_something();
    
    volatile unsigned long long f = Factorial<23>::value;
    volatile unsigned long long fib = Fibonacci<23>::value;
    
    // Prevent optimization
    if (f == 0) std::cout << "Impossible" << std::endl;
}
