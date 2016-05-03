#include <stdio.h>

int find(int* matrix, int rows, int cols, int number)
{
	if (matrix != NULL && rows > 0 && cols > 0)
	{
		int row = 0;
		int col = cols - 1;
		while (row < rows && col < cols)
		{
			int num = matrix[row * cols + col];
			if (num < number)
			{
				row++;
			}
			else if (num > number)
			{
				col--;
			}
			else
			{
				return 1;
			}
		}
	}

	return 0;
}

int main(int argc, char* argv[])
{
	int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("%d\n", find(*a, 3, 3, 5));
	return 0;
}
