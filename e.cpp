
#include <iostream>
#include <vector>
#include <bitset>
#include <chrono>
#include <limits>

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


template <int S>
class eratos
{
    static_assert(S < 30000, "test");

public:
    void operator()(void)
	{
        std::cout << "\n\nEratosfen functor" << std::endl;
        std::bitset<S> v;

        for(unsigned int i=2; i < (S/2); i++)
		{
            unsigned int j = i;
            while(j < S)
			{
				j += i;
				v[j] = true;
			}
		}

        int cnt = 0;
        for(unsigned int i=0; i < S; i++)
		{
			if(v[i] == false)
            {
				std::cout << i << "  ";
                cnt++;
            }
		}
        std::cout << "\nНайдено " << cnt << " чисел" << std::endl;
	}
};



int main()
{
	unsigned long long int a = 1234567890;
	unsigned long long int b = 12;
	int cnt = 0;


	std::cout << "First: " << measure<>::execution([&]()
		{
			while(a != b)
			{
				if(a > b)
					a = a-b;
				else
					b = b-a;
				cnt++;
			}
		}) << " ms\n";

	std::cout << a << "\n";
	std::cout << cnt << std::endl;

    a = 1234567895;
	b = 12;
	cnt = 0;

	std::cout << "Second: " << measure<>::execution([&]()
		{
			while((a != 0) && (b != 0))
			{
				if(a > b)
					a = a % b;
				else
					b = b % a;
				cnt++;
			}
		}) << " ms\n";

	std::cout << a << "  " << b << "\n";
	std::cout << cnt << std::endl;


	// Быстрое возведение в степень



	// Решето Эратосфена
//    eratos<1000000000> e;

//    auto t = measure<>::execution(e);

//	std::cout << "\nexecution " << t << " ms" << std::endl;



	return 0;
}
