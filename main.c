#include <stdio.h>
#include "main.h"

int main(void)
{
    char ch = 'A';
    char *str = "Hello, world!";
    int percent = 25;

    _printf("Let's try to printf a simple sentence.\n");
    printf("Let's try to printf a simple sentence.\n");

    _printf("Character: %c\n", ch);
    printf("Character: %c\n", ch);

    _printf("String: %s\n", str);
    printf("String: %s\n", str);

    _printf("Percent: %%\n");
    printf("Percent: %%\n");

    _printf("Unknown format: %%%d\n", percent);
    printf("Unknown format: %%%d\n", percent);

    return (0);
}

