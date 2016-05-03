#include <stdio.h>

void swap_odd_even(int *a, unsigned int length)
{
	if (a == NULL || length <= 0)
		return;

	int *p1 = a;
	int *p2 = a + length - 1;
	while (p1 < p2)
	{
		// untile p1 is even
		while (p1 < p2 && (*p1 & 0x1) != 0)
			p1++;

		// untile p2 is odd
		while (p1 < p2 && (*p2 & 0x1) == 0)
			p2--;

		if (p1 < p2)
		{
			int temp = *p2;
			*p2 = *p1;
			*p1 = temp;
		}
	}
}

int main(int argc, char* argv[])
{
	int a[5] = {1, 2, 3, 4, 5};
	printf("Before SWAP:\t1\t2\t3\t4\t5\n");
	swap_odd_even(a, 5);
	printf("After SWAP:\t");
	for (int i = 0; i < 5; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");

	return 0;
}
