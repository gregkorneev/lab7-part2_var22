#pragma once
#include <random>

// Поиск НОД двух очень больших чисел

// Основной метод — алгоритм Евклида (быстрый)
unsigned long long gcd_euclid(unsigned long long a, unsigned long long b);

// Наивный метод — полное вычитание (грубая сила)
unsigned long long gcd_naive(unsigned long long a, unsigned long long b);

// Пара чисел для эксперимента
struct GcdPair {
    unsigned long long a;
    unsigned long long b;
};

// Генерация случайной пары (от 1 до max_value)
GcdPair gen_random_pair(unsigned long long max_value, std::mt19937& rng);

// Замер времени работы алгоритмов
long long measure_ms_euclid(unsigned long long a, unsigned long long b, unsigned long long& out_gcd);
long long measure_ms_naive(unsigned long long a, unsigned long long b, unsigned long long& out_gcd);
