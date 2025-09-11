#include <stdio.h>
#include <string.h>

int GCD(int a, int b)
{
    int outa = a, outb = b;
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    printf("The GCD of the number %d and %d is: %d\n", outa, outb, a);
    return a;
}

int main()
{
    // Splitting based on spaces
    char str[] = "Hey this is the string to split by spaces";
    int i = 0;
    int j = 0;
    int strLength = strlen(str);
    while (i <= strLength)
    {
        if (str[i] == ' ')
        {
            printf("space at index: %d\n", i);
            char word[100] = "";
            int w = 0;
            while (j < i)
            {
                word[w] = str[j];
                // char temp_char[2] = "";
                // temp_char[0] = str[j];
                // temp_char[1] = '\0';
                // strcat(word, temp_char);
                j++;
                w++;
            }
            printf("%s\n", word);
            j = i + 1;
        }
        if (i == strLength)
        {
            for (int i = j; i < strLength; i++)
            {
                printf("%c", str[i]);
            }
        }
        i++;
    }
    printf("\n");

    // counting digits of a number
    int number = 1234;
    int digits = 0;
    if (number == 0)
    {
        digits = 1;
    }
    else
    {
        while (number > 0)
        {
            number /= 10;
            digits++;
        }
    }
    printf("The number of digits are: %d\n", digits);

    // Reverse a number
    int revNum = 12345;
    int rev = 0;
    if (revNum / 10 <= 0)
    {
        rev = revNum;
    }
    else
    {
        while (revNum > 0)
        {
            rev = rev * 10 + revNum % 10;
            revNum /= 10;
        }
    }
    printf("The reverse of the number is: %d\n", rev);

    // finding the gcd - greatest common devisor
    int a = 56;
    int b = 98;
    int outa = a, outb = 98;
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    printf("The GCD of the number %d and %d is: %d\n", outa, outb, a);

    // finding the lcm - lowest common multiple
    int la = 15, lb = 35;
    int lcm = (la > lb) ? la : lb;
    while (1)
    {
        if (lcm % la == 0 && lcm % lb == 0)
        {
            printf("The LCM for %d and %d is %d\n", la, lb, lcm);
            break;
        }
        lcm++;
    }
    // formula for lcm using gcd
    lcm = la * lb / GCD(la, lb);
    printf("The LCM for the %d and %d using GCD is %d\n", la, lb, lcm);

    // find simplifiedd fraction of two numbers
    int sa = 42, sb = 56;
    int gcd = GCD(sa, sb);
    printf("Simplified fraction is for 42/56 is: %d/%d\n", sa / gcd, sb / gcd);
    return 0;
}