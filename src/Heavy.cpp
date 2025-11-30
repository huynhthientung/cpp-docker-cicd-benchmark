#include <iostream>

// Recursive template to force compiler to generate many instantiations
template<int N>
struct Factorial {
    static const unsigned long long value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0> {
    static const unsigned long long value = 1;
};

// Another heavy template chain
template<int N>
struct Fibonacci {
    static const unsigned long long value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};

template<>
struct Fibonacci<0> {
    static const unsigned long long value = 0;
};

template<>
struct Fibonacci<1> {
    static const unsigned long long value = 1;
};

// Instantiate a lot of templates
void run_heavy_computation() {
    volatile unsigned long long f10 = Factorial<10>::value;
    volatile unsigned long long f20 = Factorial<20>::value;
    
    // This part is just to ensure the compiler doesn't optimize everything away completely
    // without doing some work. The real work is in the template instantiation.
    std::cout << "Factorial(10): " << f10 << std::endl;
    std::cout << "Factorial(20): " << f20 << std::endl;
    
    // Force more instantiations
    volatile unsigned long long fib10 = Fibonacci<10>::value;
    volatile unsigned long long fib20 = Fibonacci<20>::value;
    // volatile unsigned long long fib40 = Fibonacci<40>::value; // This might be too heavy for runtime if not constant folded, but here it is constant folded.

    std::cout << "Fibonacci(10): " << fib10 << std::endl;
    std::cout << "Fibonacci(20): " << fib20 << std::endl;
}
