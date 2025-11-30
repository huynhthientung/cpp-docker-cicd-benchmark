#pragma once

template<int N>
struct Factorial {
    static const unsigned long long value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0> {
    static const unsigned long long value = 1;
};

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

// A template that does a lot of type instantiations
template<typename T, int N>
struct HeavyType {
    using Next = typename HeavyType<T, N-1>::Next;
    static void do_something() {
        volatile auto v = Factorial<N % 20>::value;
        (void)v;
    }
};

template<typename T>
struct HeavyType<T, 0> {
    using Next = T;
    static void do_something() {}
};
