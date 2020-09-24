









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



