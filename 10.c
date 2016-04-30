#include <stdio.h>

int numOf1(int n)
{
    int count = 0;
    while (n)
    {
      if (n & 1)
	count++;

      n = n >> 1;
    }

    return count;
}

int main(int argc, char* argv[])
{
    printf("%d\n", numOf1(3));
    return 0;
}
