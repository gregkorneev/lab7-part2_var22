#include "include.h"

// Наивный алгоритм НОД: многократное вычитание
// Работает только для относительно небольших чисел (для эксперимента)
unsigned long long gcd_naive(unsigned long long a, unsigned long long b) {
    if (a == 0) return b;
    if (b == 0) return a;

    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}
