
#include <iostream>
#include <vector>
#include <bitset>
#include <chrono>
#include <limits>
#include <memory>

#include "pow.cpp"
#include "sieve.cpp"
#include "fibo.cpp"

// Отсюда
// https://stackoverflow.com/a/21995693
template<typename TimeT = std::chrono::milliseconds>
struct measure
{
	template<typename F, typename ...Args>
	static typename TimeT::rep execution(F&& func, Args&&... args)
	{
		auto start = std::chrono::steady_clock::now();
		std::forward<decltype(func)>(func)(std::forward<Args>(args)...);
		auto duration = std::chrono::duration_cast< TimeT>
							(std::chrono::steady_clock::now() - start);
		return duration.count();
	}
};



int main()
{
	unsigned long long int a = 1234567890;
	unsigned long long int b = 12;
	int cnt = 0;

    {
        // Быстрое возведение в степень
        std::cout << otusalg::pow<unsigned long long int>(2, 2) << std::endl;
        std::cout << otusalg::pow<unsigned long long int>(5, 12) << std::endl;
        std::cout << otusalg::pow<unsigned long long int>(4, 12) << std::endl;
        std::cout << otusalg::pow<unsigned long long int>(3, 12) << std::endl;
        std::cout << otusalg::pow<unsigned long long int>(3, 15) << std::endl;
        std::cout << otusalg::pow<unsigned long long int>(11, 12) << std::endl;

        std::cout << "gmpxxx\n";

        otusalg::gmpxxx m3(5);
        std::cout << otusalg::pow<otusalg::gmpxxx>(m3, 12) << std::endl;
        otusalg::gmpxxx m4(123);
        std::cout << otusalg::pow<otusalg::gmpxxx>(m4, 456) << std::endl;
    }


    {
        // Решето Эратосфена
        auto e = std::make_unique<eratos>();

        auto t = measure<std::chrono::microseconds>::execution(*e, 100000);
        std::cout << "\nexecution " << t << " us" << std::endl;
        std::cout << "Found " << e->result().size() << " numbers" << std::endl;
    }

    {
        // Числа Фибоначчи
        fibo_sum f;
        auto t = measure<std::chrono::microseconds>::execution(f, 900);
        std::cout << "\nexecution fibo_summ " << t << " us" << std::endl;
    }

    {
        // Числа Фибоначчи
        fibo_alg f;
        auto t = measure<std::chrono::microseconds>::execution(f, 900);
        std::cout << "\nexecution fibo_alg " << t << " us" << std::endl;
    }

    {
        // Числа Фибоначчи
        fibo_matrix f;
        auto t = measure<std::chrono::microseconds>::execution(f, 900);
        std::cout << "\nexecution fibo_matrix " << t << " us" << std::endl;
    }

    return 0;
}
