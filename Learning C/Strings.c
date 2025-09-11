#include <stdio.h>
#include <string.h>

int main()
{
    /*Info:
        In C there is not datatype as string as in reality the string is just the array of characters,
        so instead of string we will be using the char array and pointers.
    */
    char string[] = "this is the string 1";
    printf("%s\n", string);

    // string of fixed length
    /*'\0' which marks the ending of the string or else the garbage value stored in the memory will be continue printing!*/
    char string2[6] = "Hello"; // space for 5 chars + '\0'
    printf("%s\n", string2);

    // storing string using pointers to an character array
    // using this method only allow us to read the string but not manipulate it
    char *name = "John Smith";
    int age = 18;
    printf("Age of %s is %d\n", name, age);

    // string functions - to use them we need to include <string.h> string header.
    // strn are more stable functions which also needs additional max parameter

    // strlen(str): get length of the string
    printf("length of name: %d\n", strlen(name));

    // strncmp(str1, str2, max_compare_length): returns 0 if strings are equal
    if (strncmp(name, "John", 4) == 0)
    {
        printf("The name John Smith contains John in it! 😎\n");
    }

    // strncat(str1, str2, max_concat_length): string concat
    char dest[100] = "Hello";
    char src[] = "World";
    strncat(dest, " ", 2);
    printf("%s\n", dest);
    strncat(dest, src, strlen(src));
    printf("%s\n", dest);
    strcat(dest, ", strcat(): easier way but less stable!");
    printf("%s\n", dest);

    /* sprintf(str, "%s %s" (formatting), str1, str2):  It operates similarly to printf(),
    but instead of printing the formatted output to the console, it writes it to a specified character array in memory.*/

    char fullname[] = "Full Name";
    // the write the formatted output to the memory of var fullname and it also avoids overflowing for not fixed sized local string array
    sprintf(fullname, "%s: %s", fullname, name);
    printf("%s\n", fullname);
    // stable sprintf() => snprintf()
    snprintf(fullname, 100, "%s: %s", fullname, name); // formatted output can be of max length of 100
    printf("%s\n", fullname);

    /* To empty the memory of specific char array variable,
        name[0] = "\0"; // only can be done to the pointer character array
    */

    return 0;
}