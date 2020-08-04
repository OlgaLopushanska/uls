#include "uls.h"

static void print_table2(char **yy,int c, int col, int *par);

static void print_st(char *yy, int max, int *par);

void mx_print_table(int c, int *titi, char **yy, int *par) {
    int rest = 0;
    int y = 0;
    int max = 0;
    int b = 0;
    int col = 0;
    struct winsize wine;

    ioctl(1, 1074295912, &wine);
    y = par[6] > 1 ? par[6] : wine.ws_col;
    for (b = 0; b < c; b++)
        max = (titi[b] > max) ? titi[b] : max;
    max = (max % 8 != 0) ? (max / 8) * 8 + 8 : max + 8;    
    while(rest <= y && col < c) {
        col++;
        rest = col * max;
    }      
    col =  rest <= y ? col : col - 1;
    col = col < 1 || par[1] ? 1 : col;
    par[45] = max;
    print_table2(yy, c, col, par);
    free(titi);
    return;
}

static void print_table2(char **yy,int c, int col, int *par) {
    int a = 0;
    int b = 0;
    int ind = 0;
    int counter = (c % col) != 0 ? (c / col) +1 : c/col;

    for (b = 0; b < counter; b++) {
        for (a = 0; a < col; a++) {
            ind = b + a * counter;
            if (ind < c) {
                par[46] = a != col - 1 && b + (a + 1) * counter < c;
                print_st(yy[ind], par[45], par);
            }
        }
        write(1, "\n",1);
    }
}

static void print_st(char *yy, int max, int *par) {
    int tab = 0;
    int flag = par[46];
    char *t = NULL;
    int len = 0;
    struct stat u;
    
    t = mx_memrchr(yy, '/', mx_strlen(yy)); 
    t = (t == NULL) || par[48] ? yy : &t[1];
    write(1, t, mx_strlen(t));
    lstat(yy, &u);
    par[46] = par[25] && ((u.st_mode & MX_IFMT) == MX_IFDIR) ? 1 : 0;
    par[46] ? write(1,"/",1) : 0;
    len = par[46] ? max - (mx_strlen(t) + 1) : max- mx_strlen(t);
    tab = len % 8;
    tab = tab == 0 ? (len) / 8 - 1 : (len) / 8 ;
    if ((par[46] ? mx_strlen(t) + 1 : mx_strlen(t))< max && flag)
        for (int st = 0; st <= tab; st++)
            write(1, "\t", 1);
}
