#include <stdio.h>

char firstUniqueChar(char *str)
{
	if (str == NULL) return '\0';

	unsigned int hashTable[256];
	for (int i = 0; i < 256; i++)
		hashTable[i] = 0;

	char *s = str;
	while (*s != '\0')
		hashTable[*(s++)]++;

	s = str;
	while (*s != '\0')
	{
		if (hashTable[*s] == 1)
			return *s;
		s++;
	}

	return '\0';
}

int main(int argc, char* argv[])
{
	char *str = "abaccdeff";
	printf("%c\n", firstUniqueChar(str));

	return 0;
}
