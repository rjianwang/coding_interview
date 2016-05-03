#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_num(char* number)
{
	int n = strlen(number);
	int isBeginning0 = 1;
	for (int i = 0; i < n; i++)
	{
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = 0;
		if (!isBeginning0)
		{
			printf("%c", number[i]);
		}
	}
}

void PrintToMaxOfNDigitsRecursibely(char* number, int length, int index)
{
	if (index == length - 1)
	{
		print_num(number);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';
		PrintToMaxOfNDigitsRecursibely(number, length, index + 1);
	}
}

void print(int n)
{
	if (n <= 0)
		return;

	char* number = (char*)malloc(sizeof(char) * (n + 1));
	number[n] = '\0';
	for (int i = 0; i < 10; i++)
	{
		number[0] = i + '0';
		PrintToMaxOfNDigitsRecursibely(number, n, 0);
	}
	printf("\n");

	free(number);
}

int main(int argc,char* argv[])
{
	print(1);
	return 0;
}
