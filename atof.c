#include <ctype.h>

// parse a decimal string to double value
// get sign and value with out dot, and divide by digit after dot
double atof(char str[]) {
    double result = 0;
    double digit_after_dot = 1;
    double sign;
    int i;

    for (i = 0; isspace(str[i]); i++)                           // skip space character
        continue;

    if (str[i] == '-')                                          // get if there is a sign character
        sign = -1;
    else
        sign = 1;
    
    for (; isspace(str[i]) || !isdigit(str[i]); i++)            // skip until that is a number character
        continue;

    for (; isdigit(str[i]); i++)                                // get value before dot
        result = result * 10 + (str[i] - '0');

    if (str[i] == '.')                                          // find dot
        i ++;
    
    for(; isdigit(str[i]); i++) {                               // get value after dot
        result = result * 10 + (str[i] - '0');               
        digit_after_dot *= 10;
    }

    return sign * result / digit_after_dot;                     // calculate
}

