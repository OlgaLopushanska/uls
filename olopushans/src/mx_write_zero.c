#include "uls.h"

void mx_write_zero(char *st) {
    int n = mx_strlen(st);

    for (int a = 0; a < n; a++)
        st[a] = '\0';
}
