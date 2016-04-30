#include <stdio.h>

long long Fibonacci(unsigned n)
{
	if (n < 2)
		return (n - 1);

	long long fib = 0;
	long long fibMinusOne = 1;
	long long fibMinusTwo = 0;
	for (unsigned i = 0; i < n; i++)
	{
		fib = fibMinusOne + fibMinusTwo;
		fibMinusTwo = fibMinusOne;
		fibMinusOne = fib;
	}

	return fib;
}

int main(int argc, char* argv[])
{
	printf("%lld\n", Fibonacci(10));
	return 0;
}
