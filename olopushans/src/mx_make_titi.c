#include "uls.h"

int *mx_make_titi(int c, char **yy, int *par) {
    int b = 0;
    int *titi = NULL;
    char *temp = NULL;
    struct stat u;

    titi = (int*)malloc(sizeof(int*) * c);
    for (b = 0; b < c; b++) {
        lstat(yy[b], &u);
        temp = mx_memrchr(yy[b], '/', mx_strlen(yy[b]));
        titi[b] = (temp == NULL) || par[48] ? 
                  mx_strlen(yy[b]) : mx_strlen(&temp[1]);
        titi[b] = par[25] && ((u.st_mode & MX_IFMT) == MX_IFDIR) ? 
                  titi[b] + 1 : titi[b];
    }
    return titi;
}
