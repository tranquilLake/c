#include <stdio.h>

double atof(char str[]);

int main(void) {

    char str[] = "123.321";
    double result = 0;

    result = atof(str);
    printf("%f", result);

    return 0;
}