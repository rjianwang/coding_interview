#include <stdio.h>
#include <string.h>

void replace_blank(char string[], int length)
{
	if (string == NULL || length <= 0 )
		return;

	int num_blank = 0;
	int length_new = 0;
	int length_orig = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		length_orig++;
		if (string[i] == ' ')
			num_blank++;
		i++;
	}

	length_new = num_blank * 2 + length_orig;
	if (length_new > length)
		return;

	int index_orig = length_orig;
	int index_new = length_new;
	while (index_orig >= 0 && index_new > index_orig)
	{
		if (string[index_orig] == ' ')
		{
			string[index_new--] = '0';
			string[index_new--] = '2';
			string[index_new--] = '%';
		}
		else
		{
			string[index_new--] = string[index_orig];
		}
		index_orig--;
	}
}

int main(int argc, char* argv[])
{
	char str[50] = "We are happy.";
	printf("Original string: %s\n", str);
	replace_blank(str, 50);
	printf("New string: %s\n", str);

	return 0;
}
