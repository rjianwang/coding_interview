#include <stdio.h>

long max_sum(int a[], int n)
{
	long sum = 0;
	long max = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || sum <= 0)	sum = a[i];
		else if (sum > 0)
		{
			sum += a[i];
		}
		if (sum > max)
			max = sum;
	}

	return max;
}

int main(int argc, char* argv[])
{
	int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
	printf("%ld\n", max_sum(a, 8));
	return 0;
}
