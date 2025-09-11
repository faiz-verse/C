#include <stdio.h>

int main()
{
    int numbers[5];
    numbers[0] = 1;
    numbers[1] = 1;
    numbers[2] = 1;
    numbers[3] = 1;
    for (int i = 0; i < 5; i++)
    {
        printf("Number at index %d is %d\n", i, numbers[i]);
    }
}