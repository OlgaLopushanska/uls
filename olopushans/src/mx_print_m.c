#include "uls.h"

static void print_m_name(char *yy, int *rest, int t, int *par);

void mx_print_m(int y, char **yy, int *par) {
    struct winsize wine;
    int t = 0;
    struct stat u;
    int rest = 0;

    ioctl(0, 1074295912, &wine);
    t = par[6] > 1 ? par[6] : wine.ws_col;

    for (int a = 0; a < y; a++) {
        lstat(yy[a], &u);
        par[44] = a < y - 1;
        par[45] = ((u.st_mode & MX_IFMT) == MX_IFDIR) && par[25] ? 1 : 0;
        print_m_name(yy[a], &rest, t, par);
	}
}

static void print_m_name(char *yy, int *rest, int t, int *par) {
    char *ch = NULL;

    ch = (char*)mx_memrchr(yy, '/', mx_strlen(yy));
    ch = (ch == NULL) || par[48] ? yy : &ch[1];
    if ((*rest + mx_strlen(ch) + (par[45] ? 4 : 3) ) > t) {
        write(1, "\n", 1);
        *rest = 0;
    }
    write(1, ch, mx_strlen(ch));
    par[45] ? write(1,"/",1) : 0;
    par[44] ? write(1,", ",2) : write(1,"\n",1);
    *rest = *rest + mx_strlen(ch)+(par[45] ? 3 : 2);
}
