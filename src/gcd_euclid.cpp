#include "include.h"

// Алгоритм Евклида (через деление по модулю)
unsigned long long gcd_euclid(unsigned long long a, unsigned long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    while (b != 0) {
        unsigned long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}
