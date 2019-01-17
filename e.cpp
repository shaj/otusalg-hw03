
#include <iostream>
#include <vector>
#include <bitset>
#include <chrono>
#include <limits>
#include <memory>

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

	std::vector<unsigned int> r;

public:
	void operator()(unsigned int n)
	{
		std::cout << "\n\nEratosfen functor" << std::endl;
		
		// std::bitset<n> v;
		std::cout << "trace 1" << std::endl;
		std::vector<bool> v(n, false);
		std::cout << "trace 2" << std::endl;
		r.empty();
		std::cout << "trace 3" << std::endl;
		if(n > 100) r.reserve(n / 100);
		std::cout << "trace 4" << std::endl;

std::cout << "Find " << measure<std::chrono::microseconds>::execution([&]()
{
		for(unsigned int i=2; i < (n/2); i++)
		{
			unsigned int j = i * 2;
			while(j < n)
			{
				v[j] = true;
				j += i;
			}
		}
}) << " us\n";

		std::cout << "trace 5" << std::endl;

std::cout << "Emplace " << measure<std::chrono::microseconds>::execution([&]()
{
		for(unsigned int i=0; i < n; i++)
		{
			if(v[i] == false)
			{
				r.emplace_back(i);
			}
		}
}) << " us\n";

		std::cout << "trace 6" << std::endl;
	}

	const auto &result() const
	{
		return r;
	}

};



class fibo
{

public:
	void operator()(int n)
	{
		unsigned long long int a = 1;
		unsigned long long int b = 1;
		unsigned long long int f;
		for(int i=0; i<(n-2); i++)
		{
			f = a + b;
			a = b;
			b = f;
		}
		std::cout << "Fibo for n = " << n << " is " << f << std::endl;
	}
};


class fibo1
{

public:
	void operator()(int n)
	{
		unsigned long long int a = 1;
		unsigned long long int b = 1;
		unsigned long long int f;
		for(int i=0; i<n; i++)
		{
			f = a + b;
			a = b;
			b = f;
		}
		std::cout << "Fibo for n = " << n << " is " << f << std::endl;
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

	std::cout << "Alg 1: " << a << "\n";
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
	std::cout << "Alg 2: " << std::max(a, b) << "\n";
	std::cout << cnt << std::endl;


	// Быстрое возведение в степень



	{
		// Решето Эратосфена
		auto e = std::make_unique<eratos>();

		auto t = measure<std::chrono::microseconds>::execution(*e, 100000);
		std::cout << "\nexecution " << t << " us" << std::endl;
		std::cout << "Found " << e->result().size() << " numbers" << std::endl;
	}

	{
		fibo f;
		auto t = measure<>::execution(f, 900);
		std::cout << "\nexecution " << t << " ms" << std::endl;
	}

	return 0;
}
