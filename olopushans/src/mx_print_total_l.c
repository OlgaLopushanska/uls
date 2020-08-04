#include "uls.h"

static void print_total_l2 (struct stat u, int *size, int *par);

static void print_total_l3 (struct stat u, int *size, int *par);

void mx_print_total_l(char **yy, int c, int *size, int *par) {
    int b = 0;
    struct stat u;
    int res = 0;

    for (b = 0; b < c; b++) { 
        res = lstat(yy[b], &u);
        print_total_l2 (u, size, par);
        print_total_l3 (u, size, par);
    }
    if (par[42] > 0 && c > 0) {
        mx_printstr("total ");
        mx_printint(size[4]);
        write(1, "\n", 1);
    }
}

static void print_total_l2 (struct stat u, int *size, int *par) {
    int res = 0;
    struct passwd *t = NULL;
    char *str = NULL;

    if (!par[21]) {
        t = getpwuid(u.st_uid);
        size[0] = t ? (size[0] < (res = mx_strlen(t->pw_name)) ? res
            : size[0]) : 0;
        res = mx_max_group(getgrgid(u.st_gid), u);
        size[1] = size[1] < res  ? res : size[1];
    }
    else {
        str = mx_itoa(u.st_uid);
        size[0] = size[0] < (res = mx_strlen(str)) ? res : size[0];
        free(str);
        str = mx_itoa(u.st_gid);
        size[1] = size[1] < (res = mx_strlen(str)) ? res : size[1];
        free(str);
    }
}

static void print_total_l3 (struct stat u, int *size, int *par) {
    int res = 0;
    char *str = NULL;

    str = mx_itoa(u.st_nlink);
    size[2] = size[2] < (res = mx_strlen(str)) ? res : size[2];
    free(str);
    str = mx_itoa(u.st_size);
    size[3] = size[3] < (res = mx_strlen(str))? res : size[3];
    free(str);
    size[3] = par[15] ? 5 : size[3];
    size[4] = size[4] + u.st_blocks;
    if ((u.st_mode & MX_IFMT) == MX_IFCHR || (u.st_mode & MX_IFMT) == MX_IFBLK)
        size[3] = size[3] < 8 ? 8 : size[3];
}
