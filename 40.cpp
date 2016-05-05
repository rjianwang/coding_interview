#include <iostream>

int findFirstBit1(int num)
{
	int index = 0;
	while (((num & 1) == 0) && (index < 8 * sizeof(int)))
	{
		num = num >> 1;
		index++;
	}

	return index;
}

bool isBit1(int num, int index)
{
	num = num >> index;
	return (num & 1);
}

void findUniqueTwo(int a[], int n, int *num1, int *num2)
{
	if (a == NULL || n < 2) return;

	int result_or = 0;
	for (int i = 0; i < n; i++)
		result_or ^= a[i];
	
	unsigned int indexOf1 = findFirstBit1(result_or);

	*num1 = 0;
	*num2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (isBit1(a[i], indexOf1))
			*num1 ^= a[i];
		else
			*num2 ^= a[i];
	}
}

int main(int argc, char* argv[])
{
	int a[] = {2, 4, 3, 6, 3, 2, 5, 5};
	
	int *num1 = new int;
	int *num2 = new int;
	findUniqueTwo(a, 8, num1, num2);
	std::cout << *num1 << "\t" << *num2 << std::endl;

	delete num1;
	delete num2;

	return 0;
}
