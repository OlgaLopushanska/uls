#include "uls.h"

void mx_print_colum(int size, int len, int data, const char *ch) {
    int d = 0;

    if (size > len && size > 0)
        for (d = 0; d < size - (len); d++)
          mx_printstr(" ");   
    if (ch == NULL){
        mx_printint(data);
        write(1, " ", 1);
    }
    else {
        mx_printstr(ch);
        data > 0 ? write(1, "  ", 2) : write(1, "", 0);
    }
    if (-size > len && size < 0)
        for (d = 0; d < -size - (len); d++)
          mx_printstr(" ");   
}
