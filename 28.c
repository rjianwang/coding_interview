#include <stdio.h>

void permutation_core(char *str, char* it)
{
	if (*it == '\0')
		printf("%s\n", str);
	else
	{
		for (char* p = it; *p != '\0'; p++)
		{
			char temp = *p;
			*p = *it;
			*it = temp;

			permutation_core(str, it + 1);

			temp = *p;
			*p = *it;
			*it = temp;
		}
	}
}

void permutation(char *str)
{
	if (str == NULL)	return;
	permutation_core(str, str);
}

int main(int argc, char* argv[])
{
	char a[3] = {'h', 'e', 'o'};
	printf("Original String:\t%s\n", a);
	permutation(a);
}
