#include "uls.h"

char *mx_convert_to_hex(int num) {
    char *res = NULL;
    char *number = mx_itoa(num);

    if (num > 256) {
        free(number);
        number = mx_nbr_to_hex(num);
        res = mx_strjoin("0x00000", number);
        free(number);
    }
    else if (num > 99 && num < 1000)
        res = number;
    else if (num <= 99 && num > 9) {
        res = mx_strjoin(" ", number);
        free(number);
    }
    else {
        res = mx_strjoin("  ", number);
        free(number);
    }
    return res; 
}
