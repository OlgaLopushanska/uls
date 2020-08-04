#include "uls.h"

static void print_size_l2(struct stat u);

static char *print_size_l3(struct stat u, char *yy, int *size, int *par);

char *mx_print_size_l(struct stat u, char *yy, int *size, int *par) {
    char *buf = NULL;

    if ((u.st_mode & MX_IFMT)== MX_IFCHR || (u.st_mode & MX_IFMT) == MX_IFBLK)
        print_size_l2( u);
    else   
        buf = print_size_l3( u, yy, size, par);
    return buf;
}

static void print_size_l2(struct stat u) {
    char *tim = NULL;

    tim = mx_convert_to_hex((u.st_rdev >> 24) & 0xff);
    mx_print_colum(3, mx_strlen(tim), -5, tim);
    free(tim);
    write(1, ", ", 2);
    tim = mx_convert_to_hex(u.st_rdev& 0xffffff) ; 
    mx_print_colum(3, mx_strlen(tim), -5, tim);
    free(tim);
    write(1," ",1);
}

static char *print_size_l3(struct stat u, char *yy, int *size, int *par) {
    char *tim = NULL;
    int rez = 0;
    char *buf = mx_strnew(sizeof(char*) * 900);

    if ((u.st_mode & MX_IFMT) != MX_IFLNK) { 
        tim = par[15] ? mx_size_bytes(u.st_size) : mx_itoa(u.st_size); 
        mx_print_colum(size[3], mx_strlen(tim), 0, tim);
        write(1, " ", 1);
    }
    else {
        rez = readlink(yy, buf, 300);
        tim = par[15] ? mx_size_bytes(rez) : mx_itoa(rez); 
        mx_print_colum(size[3], mx_strlen(tim), 0, tim);
        write(1, " ", 1);
    }
    free(tim);
    return buf;
}
