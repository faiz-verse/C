#include <stdio.h>

int sum(int num)
{
    static int sum = 0;
    sum += num;
    return sum;
}

long long generateFibo()
{
    static long long a = 0, b = 1; // a and b will persist
    long long next = a;            // temporary to return
    long long temp = a + b;        // temporary to assign to b
    a = b;
    b = temp;
    return next;
}

int main()
{
    // finding sum using the static variable to sum up on every function call
    printf("Sum is %d\n", sum(50));
    printf("Sum is %d\n", sum(55));
    printf("Sum is %d\n", sum(60));

    // Fibonacci series generator using the static variable
    int range = 20;
    for (int i = 1; i < range; i++)
    {
        printf("%lld ", generateFibo());
    }
    printf("\n");

    return 0;
}