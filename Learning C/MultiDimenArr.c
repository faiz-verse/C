#include <stdio.h>

int main()
{
    int foo[5];
    // sizeof(foo) returns the total size of bytes accupied by the array
    // sizeof(foo[0]) returns the bytes occupied by the single element
    // sizeof(foo) / sizeof(foo[0]) is the jugaad for the array.length function 😎
    for (int i = 0; i <= (sizeof(foo) / sizeof(foo[0])); i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    char vowels[1][5] = {{'a', 'e', 'i', 'o', 'u'}};
    int num[3][2] = {{1, 2}, {3, 4}, {5, 6}};

    // valid
    char validVowels[][5] = {{'A', 'E', 'I', 'O', 'U'}, {'a', 'e', 'i', 'o', 'u'}};

    // invalid
    // char invalidVowels1[][] = {{'A', 'E', 'I', 'O', 'U'}, {'a', 'e', 'i', 'o', 'u'}};
    // char invalidVowels2[2][] = {{'A', 'E', 'I', 'O', 'U'}, {'a', 'e', 'i', 'o', 'u'}};

    char capitalVowels[5] = {validVowels[0][0], validVowels[0][1], validVowels[0][2], validVowels[0][3], validVowels[0][4]};
    printf("\nCapital vowels: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("'%c', ", (char)capitalVowels[i]);
    }

    // exercise to get the average of marks scored by 5 students per subject (2 subject marks stored in multi dimensional array)
    int grades[2][5];
    int average;
    // sub 1
    grades[0][0] = 80;
    grades[0][1] = 70;
    grades[0][2] = 60;
    grades[0][3] = 50;
    grades[0][4] = 90;
    // sub 2
    grades[1][0] = 85;
    grades[1][1] = 40;
    grades[1][2] = 55;
    grades[1][3] = 67;
    grades[1][4] = 88;
    // display
    printf("\n\nMarks: { \n");
    for (int i = 0; i < 2; i++)
    {
        printf("    { ");
        for (int j = 0; j < 5; j++)
        {
            printf("%d, ", grades[i][j]);
        }
        printf("}, \n");
    }
    printf("}");
    // Average
    printf("\nAverage: { \n");
    for (int i = 0; i < 2; i++)
    {
        float sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += grades[i][j];
        }
        printf("    Subject %d: %.2f \n", i + 1, sum / 5);
    }
    printf("} \n");

    return 0;
}