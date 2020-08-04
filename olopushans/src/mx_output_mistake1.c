#include "uls.h"

void mx_output_mistake1(char *m, char *u, int *par) {
    char *t = NULL;

    par[43] = 1;
    t = mx_memrchr(m, '/', mx_strlen(m));
    write(2, &t[1], mx_strlen(&t[1]));
    write(2, ": ", 2);
    write(2, u, mx_strlen(u));
    write(2, ": ", 2);
    write(2, strerror(2), mx_strlen(strerror(2)));
    write(2, "\n", 1);
}
