#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// factorial recursive function
long long factorial(long long n)
{
    // base terminating condition - important for recursion to avoid infinite loop
    if (n == 0)
    {
        return 1; // return 1 when n gets to 0
    }
    else
    {
        return n * factorial(n - 1); // recursion with everytime n = n - 1
    }
}

// fabonicci
long long fabonicci(long long n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fabonicci(n - 1) + fabonicci(n - 2);
}

// Reverse a string
// char* is a return type of pointer which will point the starting address of the string
// Recursive function to actually reverse the string
void reverseHelper(char *inStr, int start, int end)
{
    if (start >= end)
        return;
    char temp = inStr[start];
    inStr[start] = inStr[end];
    inStr[end] = temp;
    reverseHelper(inStr, start + 1, end - 1);
}
char *reverseString(char *inStr)
{
    int strLength = strlen(inStr);
    char *copy = (char *)malloc(strLength * sizeof(char));
    strcpy(copy, inStr);
    reverseHelper(copy, 0, strLength - 1);
    return copy;
}

bool isPalindromeHelper(char *inStr, int start, int end)
{
    if (start >= end)
    {
        return true; // crossed or same character
    }
    if (inStr[start] != inStr[end])
    {
        return false;
    }
    return isPalindromeHelper(inStr, start + 1, end - 1);
}
// check palindrome
bool isPalindrome(char *inStr)
{
    int strLength = strlen(inStr);
    return isPalindromeHelper(inStr, 0, strLength - 1);
}

// Power of a number m^n
long long findPower(long a, long b, int *count)
{
    (*count)++;
    if (b == 0)
    {
        return 1;
    }
    // for fast optimized approach
    if (b % 2 == 0)
    {
        long long half = findPower(a, b / 2, count);
        return half * half;
    }
    return a * findPower(a, b - 1, count);
}

// finding GCD
int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return GCD(b, a % b);
}

// Binary Search
int binarySearch(int arr[], int target, int start, int end)
{
    if (start > end)
    {
        return -1; // not found
    }
    int mid = (start + end) / 2; // middle index
    if (arr[mid] == target)
    {
        return mid;
    }
    if (target < arr[mid])
    {
        return binarySearch(arr, target, start, mid - 1);
    }
    else
    {
        return binarySearch(arr, target, mid + 1, end);
    }
}

// Tower of hanoi
void solveHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    solveHanoi(n - 1, from, aux, to);                    // move n-1 from source to helper
    printf("Move disk %d from %c to %c\n", n, from, to); // move largest disk
    solveHanoi(n - 1, aux, to, from);                    // move n-1 from helper to destination
}

// Finding the occurances of alphabets in the string
void findOccurances(char *inStr, int strLength)
{
    char alphabets[256]; // store unique characters
    int alphabetsCounter = 0;

    for (int i = 0; i < strLength; i++)
    {
        bool isRepeated = false;

        // check if character already in alphabets[]
        for (int j = 0; j < alphabetsCounter; j++)
        {
            if (alphabets[j] == inStr[i])
            {
                isRepeated = true;
                break;
            }
        }

        if (!isRepeated)
        {
            alphabets[alphabetsCounter] = inStr[i];
            alphabetsCounter++;
        }
    }

    printf("\nUnique characters: ");
    for (int i = 0; i < alphabetsCounter; i++)
    {
        printf("%c ", alphabets[i]);
    }
    printf("\n\n");

    int *occurances = (int *)calloc(alphabetsCounter, sizeof(int));
    for (int i = 0; i < alphabetsCounter; i++)
    {
        for (int j = 0; j < strLength; j++)
        {
            if (alphabets[i] == inStr[j])
            {
                *(occurances + i) += 1;
            }
        }
    }

    printf("Occurances of characters: \n");
    for (int i = 0; i < alphabetsCounter; i++)
    {
        printf("%c : %d\n", alphabets[i], *(occurances + i));
    }
    printf("\n\n");

    free(occurances);
}

int main()
{
    // factorial
    printf("\nFactorial of 1: %lld\n", factorial(1));
    printf("Factorial of 5: %lld\n", factorial(5));
    printf("Factorial of 7: %lld\n\n", factorial(7));

    // fabonicci series
    printf("Fabonacci series upto 10: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%lld ", fabonicci(i));
    }
    printf("\n\n");

    // Reverse a string
    char *str = reverseString("Faizan");
    printf("Reversed: %s\n", str);
    free(str); // important!

    // check palindrome
    char *str2 = "madam";
    printf("%s is %s\n\n", str2, isPalindrome(str2) ? "Palindrome" : "not a Palindrome");

    // find power
    int recursionCount = 0;
    long long result = findPower(2, 10, &recursionCount);
    printf("2^10 = %lld\n", result);
    printf("Total recursive calls: %d\n\n", recursionCount);

    // GCD
    printf("GCD of 42 and 56 is %d\n\n", GCD(42, 56));

    // Binary search
    /*
        Binary Search works on a sorted array.
        Instead of checking every element (like linear search), it keeps halving the search range:
            1.Look at the middle element.
            2.If it equals the target → ✅ found.
            3.If target is smaller → search in the left half.
            4.If target is greater → search in the right half.
            5.Repeat until range is empty.
    */
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 4;
    int binaryResult = binarySearch(arr, target, 0, size - 1);

    if (binaryResult != -1)
    {
        printf("Element %d found at index %d\n\n", target, binaryResult);
    }
    else
    {
        printf("Element %d not found\n\n", target);
    }

    // Tower of Hanoi
    solveHanoi(3, 'A', 'C', 'B');

    // Find the number of occurances of characters from a string using recursive function
    char *string1 = "faizan is back";
    int string1length = strlen(string1);
    findOccurances(string1, string1length);

    return 0;
}