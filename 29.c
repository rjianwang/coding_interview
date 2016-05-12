#include <stdio.h>

int halfNumber(int a[], int n)
{
    if (a != NULL && n <= 0)
    {
        printf("Invalid input.\n");
        return -1;
    }
    int result = a[0];
    int times = 1;
    for (int i = 1; i < n; i++)
    {
        if (times == 0)
        {
            result = a[i];
            times = 1;
        }
        else if (a[i] == result)
            times++;
        else
            times--;
    }
    
    // 判断找到的数字出现次数是否超过一半
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (result == a[i])
            count++;
    }
    if (count * 2 <= n)
    {
        printf("Value not found.\n");
        return -1;
    }

    return result;
}

int main(int argc, char* argv[])
{
    int a[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    printf("%d\n", halfNumber(a, 9));
    return 0;
}
