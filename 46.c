#include <stdio.h>

long sum(int n)
{
	long s = 0;
	s = n * (n + 1) / 2;

	return s;
}

int main(int argc, char* argv[])
{
	printf("%ld\n", sum(100));

	return 0;
}
