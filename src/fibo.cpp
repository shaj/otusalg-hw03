








class fibo
{

public:
	void operator()(int n)
	{
		unsigned long long int a = 1;
		unsigned long long int b = 1;
        unsigned long long int f = 0;
		for(int i=0; i<(n-2); i++)
		{
			f = a + b;
			a = b;
			b = f;
		}
		std::cout << "Fibo for n = " << n << " is " << f << std::endl;
	}
};


class fibo_alg
{

public:
	void operator()(int n)
	{
	}
};

class fibo_matr
{

public:
    int operator()(int n)
    {
//        std::array<unsigned long long int, 4> v {1, 1, 1, 0};
        int v = 5;
        int res = 0;

        std::vector<int> buf(static_cast<std::size_t>(n/2+1));

        if(n < 2) throw std::runtime_error("Value error");
        if(n == 2) return v*v;

        int pow = 2;
        buf[0] = v*v;   // Индекс buf + 2 => степень сохраненного числа
        while(1)
        {
            pow *= 2;
            if(pow > n)
            {
                for(int i=pow/2; i<n; i++)
                    res = res * v;
                return res;
            }
            else if(pow == n)
            {
                return res*res;
            }
            else
            {
                res = res * res;
                buf[pow] = res;
            }

        }
    }
};


