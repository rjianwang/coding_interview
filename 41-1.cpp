#include <iostream>

bool sum2(int a[], int length, int sum, int *num1, int *num2)
{
	if (a == NULL || length < 1 || num1 == NULL || num2 == NULL)
		return false;

	int p = length - 1;
	int q = 0;
	while (p > q)
	{	
		long long cur_sum = a[p] + a[q];
		if (cur_sum == sum)
		{
			*num1 = a[p];
			*num2 = a[q];
			return true;
		}
		else if (cur_sum > sum)
			p--;
		else
			q++;
	}
	
	return false;
}

int main(int argc, char* argv[])
{
	int a[] = {1, 2, 4, 7, 11, 15};
	int *num1 = new int;
	int *num2 = new int;
	sum2(a, 6, 15, num1, num2);

	std::cout << *num1 << "\t" << *num2 << std::endl;

	delete num1;
	delete num2;

	return 0;
}
