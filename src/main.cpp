#include "include.h"
#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::mt19937 rng(123456);

    system("mkdir -p data");
    std::ofstream csv("data/timings_gcd.csv");
    csv << "method,max_value,time_ms,gcd,a,b\n";

    // 1) Малые максимальные значения — сравнение двух методов (наивный и Евклид)
    std::vector<unsigned long long> small_limits = {
        1'000ULL,      // 10^3
        10'000ULL,     // 10^4
        100'000ULL     // 10^5
    };

    int small_trials = 5;

    std::cout << "Сравнение наивного метода и алгоритма Евклида на малых числах:\n";
    for (unsigned long long max_val : small_limits) {
        for (int t = 0; t < small_trials; ++t) {
            GcdPair p = gen_random_pair(max_val, rng);

            unsigned long long g_naive = 0;
            long long time_naive = measure_ms_naive(p.a, p.b, g_naive);
            csv << "naive," << max_val << "," << time_naive << "," << g_naive
                << "," << p.a << "," << p.b << "\n";

            unsigned long long g_euclid = 0;
            long long time_euclid = measure_ms_euclid(p.a, p.b, g_euclid);
            csv << "euclid," << max_val << "," << time_euclid << "," << g_euclid
                << "," << p.a << "," << p.b << "\n";

            std::cout << "max=" << max_val
                      << "  a=" << p.a << "  b=" << p.b
                      << "  НОД(наивный)=" << g_naive << " (" << time_naive << " мс)"
                      << "  НОД(Евклид)=" << g_euclid << " (" << time_euclid << " мс)\n";
        }
    }

    // 2) Большие числа — только Евклид (наивный уже слишком медленный)
    std::vector<unsigned long long> big_limits = {
        1'000'000ULL,          // 10^6
        1'000'000'000ULL,      // 10^9
        1'000'000'000'000ULL   // 10^12
    };

    int big_trials = 5;

    std::cout << "\nЭксперимент на производительность алгоритма Евклида на больших числах:\n";
    for (unsigned long long max_val : big_limits) {
        for (int t = 0; t < big_trials; ++t) {
            GcdPair p = gen_random_pair(max_val, rng);

            unsigned long long g_euclid = 0;
            long long time_euclid = measure_ms_euclid(p.a, p.b, g_euclid);
            csv << "euclid," << max_val << "," << time_euclid << "," << g_euclid
                << "," << p.a << "," << p.b << "\n";

            std::cout << "max=" << max_val
                      << "  a=" << p.a << "  b=" << p.b
                      << "  НОД(Евклид)=" << g_euclid << " (" << time_euclid << " мс)\n";
        }
    }

    // Демонстрационный пример
    unsigned long long a_demo = 123456789012345ULL;
    unsigned long long b_demo = 9876543210ULL;
    unsigned long long g_demo = gcd_euclid(a_demo, b_demo);

    std::cout << "\nДемонстрационный пример:\n";
    std::cout << "a = " << a_demo << "\n";
    std::cout << "b = " << b_demo << "\n";
    std::cout << "НОД (алгоритм Евклида) = " << g_demo << "\n";

    std::cout << "\nCSV-файл сохранён: data/timings_gcd.csv\n";

    return 0;
}
