
#include <iostream>
#include <vector>
#include <chrono>

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


class eratos
{
public:
	void operator()(int n)
	{
		// if(n < 10) throw std::invalid_argument("Pfff...");

		std::cout << "\n\nEratosfen functor\n";
		std::vector<bool> v(n, false);

		for(int i=2; i < (n/2); i++)
		{
			int j = i;
			while(j < n)
			{
				j += i;
				v[j] = true;
			}
		}

		for(int i=0; i < n; i++)
		{
			if(v[i] == false)
				std::cout << i << "  ";
		}
		std::cout << "\n\n";

		// for(const auto it: v)
		// 	std::cout << it << "  ";

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

	a = 1234567890;
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
	eratos e;

	auto t = measure<>::execution(e, 90);

	std::cout << "\nexecution " << t << " ms" << std::endl;

	return 0;
}