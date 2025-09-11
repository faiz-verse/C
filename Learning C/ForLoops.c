#include <stdio.h>
#include <string.h>

int main()
{
    // Bhautik sir's favourite
    char starPattern[100] = "";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 5; j > i; j--)
        {
            strcat(starPattern, "  ");
        }
        for (int j = 0; j <= i * 2; j++)
        {
            strcat(starPattern, "* ");
        }
        strcat(starPattern, "\n");
    }
    printf(starPattern);

    // Summing up the array
    int arrToSum[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arrSize = (sizeof(arrToSum) / sizeof(arrToSum[0]));
    int sum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        sum += arrToSum[i];
    }
    printf("The sum is: %d\n", sum);

    // finding factorial
    int inFact;
    printf("Enter the number to find the factorial: ");
    scanf("%d", &inFact);
    long long factorial = 1;
    for (int i = 1; i <= inFact; i++)
    {
        factorial = factorial * i;
    }
    printf("Factorial is: %lld\n", factorial);

    // Sum of digits of a number
    int inDig;
    printf("Enter the number to find the Sum of digits: ");
    scanf("%d", &inDig);
    int sumOfDig = 0;
    for (; inDig > 0; inDig /= 10) // inDig = inDig / 10
    {
        sumOfDig += inDig % 10; // add last digit
    }
    printf("Sum of digits are: %d\n", sumOfDig);

    // Reverse a number
    long long inRev;
    printf("Enter the number to Reverse: ");
    scanf("%lld", &inRev);
    long long rev = 0;
    for (; inRev > 0; inRev /= 10) // inDig = inDig / 10
    {
        rev = rev * 10 + inRev % 10;
    }
    printf("Reverse of the number is: %lld\n", rev);

    // Check isprime
    int inPrime;
    int isPrime = 1;
    printf("Enter the number to check prime or not prime: ");
    scanf("%d", &inPrime);
    if (inPrime <= 1)
    {
        isPrime = 0;
    }
    else
    {
        for (int i = 2; i < inPrime; i++)
        {
            if (inPrime % i == 0)
            {
                isPrime = 0;
                break;
            }
        }
    }
    if (isPrime)
    {
        printf("%d is a prime number\n", inPrime);
    }
    else
    {
        printf("%d is not a prime number\n", inPrime);
    }

    // List prime numbers in range
    int inListPrime;
    int isListPrime = 1;
    printf("Enter the range to list prime numbers: ");
    scanf("%d", &inListPrime);

    if (inListPrime <= 1)
    {
        isListPrime = 0;
        printf("No prime numbers in this range!\n");
    }
    else
    {
        printf("List of prime numbers in this range: ");
        for (long long i = 2; i < inListPrime; i++)
        {
            int isPrime = 1;
            for (long long j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    isPrime = 0;
                    break;
                }
            }
            if (isPrime)
            {
                printf("%lld ", i);
            }
            else
            {
                continue;
            }
        }
        printf("\n");
    }

    int inFibo;
    printf("Enter a range for the Fibonacci Sequence: ");
    scanf("%d", &inFibo);

    long long a = 0;
    long long b = 1; // first two numbers
    printf("%d %d ", a, b);

    for (int i = 2; i < inFibo; i++)
    {
        long long fibo = a + b; // next number = sum of previous two
        printf("%lld ", fibo);

        // update for next loop
        a = b;
        b = fibo;
    }
    printf("\n");

    return 0;
}