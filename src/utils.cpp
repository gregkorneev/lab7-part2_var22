#include "include.h"
#include <chrono>

// Генерация пары случайных чисел от 1 до max_value
GcdPair gen_random_pair(unsigned long long max_value, std::mt19937& rng) {
    if (max_value < 2) max_value = 2;
    std::uniform_int_distribution<unsigned long long> dist(1, max_value);
    GcdPair p;
    p.a = dist(rng);
    p.b = dist(rng);
    return p;
}

// Замер времени: Евклид
long long measure_ms_euclid(unsigned long long a, unsigned long long b, unsigned long long& out_gcd) {
    auto t1 = std::chrono::steady_clock::now();
    out_gcd = gcd_euclid(a, b);
    auto t2 = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

// Замер времени: наивный метод
long long measure_ms_naive(unsigned long long a, unsigned long long b, unsigned long long& out_gcd) {
    auto t1 = std::chrono::steady_clock::now();
    out_gcd = gcd_naive(a, b);
    auto t2 = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}
