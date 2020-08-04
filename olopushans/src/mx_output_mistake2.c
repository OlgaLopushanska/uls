#include "uls.h"
                 
void mx_output_mistake2(char **argv,char *sign, int *par) {     
    char *temp = NULL;             

    free(par);
    temp = mx_memrchr(argv[0],'/',mx_strlen(argv[0]));
    write(2,&temp[1],mx_strlen(&temp[1]));
    write(2, ": illegal option -- ", 20);
    write(2, sign, 1);
    write(2, "\n", 1);
    write(2, "usage: ", 7);
    write(2,&temp[1],mx_strlen(&temp[1]));
    write(2, " [-ACRSTacfhlmnoprstu1] [file ...]\n", 35);
    exit (1);
}
