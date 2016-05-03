#include <stdio.h>
#include <stdlib.h>

int* merge(int *a1, int n1, int *a2, int n2)
{
	if (a1 == NULL)
		return a2;
	if (a2 == NULL)
		return a1;

	int *ret = (int*)malloc(sizeof(int) * (n1 + n2));
	int i = 0, m = 0, n = 0;
	for (; m < n1 && n < n2; i++)
	{
		for (; m < n1 && a1[m] <= a2[n]; i++, m++)
			ret[i] = a1[m];

		for (; n < n2 && a1[m] > a2[n]; i++, n++)
			ret[i] = a2[n];
	}

	for (; m < n1; i++, m++)
		ret[i] = a1[m];

	for (; n < n2; i++, n++)
		ret[i] = a2[n];

	return ret;
}

int main(int argc, char* argv[])
{
	int a1[] = {1, 3, 5};
	int a2[] = {2, 4};
	int *ret = merge(a1, 3, a2, 2);
	
	printf("a1:\t1\t3\t5\n");
	printf("a2:\t2\t4\n");
	printf("res:\t");
	for (int i = 0; i < 5; i++)
		printf("%d\t", *ret + i);
	printf("\n");

	return 0;
}
