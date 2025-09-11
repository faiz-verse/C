#include <stdio.h>

int guessNumber(int guess)
{
    if (guess < 500)
    {
        printf("Your guess is lower than the number!\n");
        return 0;
    }
    else if (guess > 500)
    {
        printf("Your guess is greater than the number!\n");
        return 0;
    }
    else
    {
        printf("Your guess is correct!\n");
        return 1;
    }
}

int main()
{
    if (guessNumber(501))
    {
        printf("OOPS! Not the correct guess!");
    }
    if (guessNumber(401))
    {
        printf("OOPS! Not the correct guess!");
    }
    if (guessNumber(500))
    {
        printf("CONGRATS BRO!!! ");
    }

    return 0;
}