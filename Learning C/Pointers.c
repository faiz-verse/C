#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
1. What is a pointer?
A pointer is just a variable that stores a memory address instead of a value.

Example:
    int a = 5;
    int *p = &a;

a is stored somewhere in memory, say at address 0x1000.
&a means “the address of a” → 0x1000.
p stores that address (0x1000).
*p means “go to that address and fetch the value there” → gives 5.

So:
p → address (0x1000)
*p → value stored at that address (5)

2. Why pointers are useful?
They let you share and modify values across functions (by reference).
They are the foundation of arrays, strings, dynamic memory, data structures, etc.

3. Strings as pointers

char *name = "John";

This means:
"John" is stored somewhere in memory: [ 'J' ][ 'o' ][ 'h' ][ 'n' ][ '\0' ]

name stores the address of 'J'
*name = 'J'
*(name+1) = 'o'
*(name+2) = 'h'
And so on, until the '\0' (null terminator).
That’s why strings in C are just pointers to characters.

4. Dereferencing
Dereferencing means “follow the pointer to the value.”

Example:
    int a = 1;
    int *pointer_to_a = &a;
    printf("%d\n", a);           // 1
    printf("%d\n", *pointer_to_a); // 1 (because *pointer_to_a = a)

5. Changing values with pointers
    int a = 1;
    int *pointer_to_a = &a;
    a += 1;             // a = 2
    *pointer_to_a += 1; // changes value at address → a = 3
    printf("%d\n", a); // 3

Both a and *pointer_to_a refer to the same memory location.
So updating one updates the other.
*/

// Swap two numbers using pointers
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swapChar(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    // Pointers
    int a = 5;
    int *p = &a; // p = &a (address where the value of a is stored), *p = a (refer to the address of a to get the value);
    printf("\nValue of a: %d\n", a);
    printf("Value of a: %d\n", *p);
    printf("Memory address of a: %p\n", p); // use %p for printing address (Hexa-decimal)
    printf("Memory address of a: %p\n\n", &a);

    // String pointers
    char *name = "Faizan";
    printf("name: %s\n", name);
    printf("*name: %c, *(name + 1): %c, *(name + 2): %c, *(name + 2): %c, *(name + 3): %c, *(name + 4): %c, *(name + 5): %c\n", *name, *(name + 1), *(name + 2), *(name + 3), *(name + 4), *(name + 5));
    printf("Memory address of name (%c): %p\n", name[0], name);
    printf("Memory address of name (%c): %p\n", name[1], name + 1);
    printf("Memory address of name (%c): %p\n", name[2], name + 2);
    printf("Memory address of name (%c): %p\n", name[3], name + 3);
    printf("Memory address of name (%c): %p\n", name[4], name + 4);
    printf("Memory address of name (%c): %p\n\n", name[5], name + 5);

    // Swap two numbers using pointers
    int x = 4, y = 5;
    printf("Values before swap: x: %d, y: %d\n", x, y);
    swap(&x, &y);
    printf("Values after swap: x: %d, y: %d\n\n", x, y);

    // printing array elements using pointers arithmetic
    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = sizeof(arr) / sizeof(*(arr)); // since, arr[0] = *(arr)
    for (int i = 0; i < arrSize; i++)
    {
        printf("Element %d address: %p, value: %d\n", i, &arr[i], *(arr + i)); // &arr[i] holds address for the value arr[i] i.e. *(arr + i)
    }
    printf("\n");

    // Find length of a string using pointers
    char *str = "Hey Faizan!";
    int lenOfStr = 0;
    while (1)
    {
        if (*(str + lenOfStr) == '\0')
        {
            break;
        }
        else
        {
            lenOfStr++;
        }
    }
    printf("Length of the string: \"%s\" is %d\n\n", str, lenOfStr);
    // OR
    str = "Hey Tahir!";
    lenOfStr = 0;
    while (*(str + lenOfStr) != '\0')
    {
        lenOfStr++;
    }
    printf("Length of the string: \"%s\" is %d\n\n", str, lenOfStr);

    // Reverse a string using pointers
    char strToRev[] = "This is the string to reverse";
    // char outStr[] = strToRev; // this is wrong because it copies the address so it will get reversed with strToRev
    // using strcpy as Assignment(=) does not copy the data but only copies the address
    char outStr[100];         // allocating space for the original string before reversing, we can also use malloc() of <stdlib.h>
    strcpy(outStr, strToRev); // copying the value of the strToRev into outStr
    char *start = strToRev;
    char *end = strToRev + strlen(strToRev) - 1;
    while (start < end)
    {
        swapChar(start, end);
        start++;
        end--;
    }
    printf("Reverse of the string \"%s\" is \"%s\"\n\n", outStr, strToRev);

    // Count vowels in a string using pointers
    char strToCheckVowels[] = "This is to check the number of vowels";
    char *pointerToCheckVowel = strToCheckVowels;
    int vowelCounter = 0;
    while (*pointerToCheckVowel != '\0') // OR pointerToCheckVowel < (strToCheckVowels + strlen(strToCheckVowels))
    {
        char ch = *pointerToCheckVowel;
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            vowelCounter++;
        }
        pointerToCheckVowel++;
    }
    printf("Number of vowels in the string \"%s\" is: %d\n\n", strToCheckVowels, vowelCounter);

    // Sum of array elements using pointer arithmetic
    int arrToSum[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sum = 0;
    int arrLength = sizeof(arrToSum) / sizeof(*(arrToSum));
    for (int i = 0; i < arrLength; i++)
    {
        sum += *(arrToSum + i);
    }
    printf("The Sum is: %d\n\n", sum);

    // Dynamic allocation
    // int arr[10]; // this is fixed sized so we cannot dynamically re-alocate memory at the run time

    /*
    using malloc() to dynamically allocate memory at runtime where,
        1. int *p - we need a pointer variable to assign the allocated memory address to the pointer so that memory can be used
        2. (int *) - type of data for which the memory is being allocated
        3. malloc(number of blocks needed * size per block which is found using sizeof(data type))
        4. malloc takes only one argument.
    malloc() does not initializes the blocks so memory contains garbage values
    */
    int *m = (int *)malloc(5 * sizeof(int));
    if (m == NULL)
    {
        printf("Memory not allocated for m!\n");
        return 1; // return 1 from the main() to indicate error
    }
    printf("Data in the allocatedd memory using malloc(): \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(m + i));
    }
    printf("\n\n");

    /*
    using calloc() which works just like malloc() but it initializes all the memory where,
        it takes 2 arguments - calloc(number of blocks, size per block)
    */
    int *c = (int *)calloc(5, sizeof(int));
    if (c == NULL)
    {
        printf("Memory not allocated for c!\n");
        return 1; // return 1 from the main() to indicate error
    }
    printf("Data in the allocated memory using calloc(): \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(c + i));
    }
    printf("\n\n");

    /*
    using realloc() which resizes the allocated memory,
        it changes size of the previously allocated memory
        it preserves old values and adds extra space
        it takes two arguments - 1. address/reference of the pointer p, 2. number of slots * size per block using sizeof(data type)
    */
    m = (int *)realloc(m, 10 * sizeof(int)); // resizing the allocated space for the *m using malloc above
    if (m == NULL)
    {
        printf("Memory not allocated for m!\n");
        return 1; // return 1 from the main() to indicate error
    }
    printf("Data in the resized allocatedd memory using realloc(): \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", *(m + i));
    }
    free(m); // free() to free the memory because 1. Always release dynamically allocated memory after use 2. Prevents memory leaks
    printf("\n\n");

    c = (int *)realloc(c, 10 * sizeof(int)); // resizing the allocated space for the *c using calloc above
    if (c == NULL)
    {
        printf("Memory not allocated for c!\n");
        return 1; // return 1 from the main() to indicate error
    }
    printf("Data in the resized allocatedd memory using realloc(): \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", *(c + i));
    }
    free(c); // free() to free the memory because 1. Always release dynamically allocated memory after use 2. Prevents memory leaks
    printf("\n\n");

    // Take a number n from user, allocate an array of size n, take input, print sum.
    int inNumber = 10;
    int *num = (int *)calloc(inNumber, sizeof(int));
    sum = 0;

    if (num == NULL)
    {
        printf("Memory not allocated for the num!\n\n");
        return 1;
    }

    printf("Memory allocated with the default data as 0 using calloc(): \n");
    for (int i = 0; i < inNumber; i++)
    {
        printf("%d ", *(num + i));
    }
    printf("\n\n");

    for (int i = 0; i < inNumber; i++)
    {
        printf("Enter the number for the position: %d: \n", i);
        *(num + i) = (i + 1) * 5;
        printf("Number inputted automatically: %d\n", *(num + i));
        sum += *(num + i);
    }
    printf("\nThe sum of the inputs is: %d\n\n", sum);
    free(num);

    // Pointer to Pointer
    int value = 10;
    int *pValue = &value;
    int **ppValue = &pValue;

    printf("Value: %d\n", value);
    printf("Value via *pValue: %d\n", *pValue);
    printf("Value via **ppValue: %d\n", **ppValue);

    printf("Address of value: %p\n", &value);
    printf("Pointer pValue holds: %p\n", pValue);
    printf("Pointer ppValue holds: %p\n", ppValue);

    // 2D array using pointer to pointer
    int rows = 2;
    int cols = 5;

    // making pointer of pointer to hold the pointer pvowels address,
    // so that we can allocate memory for each pvowels row and access using pvowel[index]
    // Allocate memory for nrows pointers
    char **pvowels = (char **)malloc(cols * sizeof(int));

    // allocating memory for each row
    for (int i = 0; i < rows; i++)
    {
        pvowels[i] = (char *)malloc(cols * sizeof(char));
    }

    // assigning capital vowels for the first row
    pvowels[0][0] = 'A';
    pvowels[0][1] = 'E';
    pvowels[0][2] = 'I';
    pvowels[0][3] = 'O';
    pvowels[0][4] = 'U';
    // assigning small vowels for the second row
    pvowels[1][0] = 'a';
    pvowels[1][1] = 'e';
    pvowels[1][2] = 'i';
    pvowels[1][3] = 'o';
    pvowels[1][4] = 'u';

    printf("\nPrinting vowels in the 2d array using pointer to pointer: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%c ", pvowels[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // free the memory
    for (int i = 0; i < rows; i++)
    {
        free(pvowels[i]);
    }
    free(pvowels);

    // pascals triangle using pointer to pointer dynamic allocation
    rows = 6;
    int **pnumbers = (int **)malloc(6 * sizeof(int *)); // pointer to pointer memory for containing row addresses
    printf("Allocated memory addresses for the pascals triangle: \n");
    printf("**pnumbers(pointing to address where row addresses are stored) pnumbers: %p\n", pnumbers);
    printf("*pnumbers(addresses of the rows where column addresses are stored) pnumbers[i]: \n");
    for (int i = 0; i < rows; i++)
    {
        pnumbers[i] = (int *)malloc((i + 1) * sizeof(int)); // pointer memory for containing cols values
        printf("row %d: %p\n", i, pnumbers[i]);
    }
    printf("\npnumbers(addresses of column where values are stored) pnumbers[i][j]: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%p ", &pnumbers[i][j]);
        }
        printf("\n");
    }

    // assigning pascals values to the allocated memory
    printf("\nPascals Triangle: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                pnumbers[i][j] = 1;
            }
            else
            {
                pnumbers[i][j] = pnumbers[i - 1][j - 1] + pnumbers[i - 1][j];
            }
            printf("%d ", pnumbers[i][j]);
        }
        printf("\n");
    }

    // free the memory
    for (int i = 0; i < rows; i++)
    {
        free(pnumbers[i]);
    }
    free(pnumbers);

    printf("\n\n");

    return 0;
}