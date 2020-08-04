#include "uls.h"

static void calc_max(char ***yy2, char **yy, int *max, int *par);

static void print_table2(char ***yy, int c, int *max, int *par);

static int calc_col(int y, int c, int *max, int *par);

static void print_s(char **yy, int *max, int *par);

void mx_print_table_s(int c, char **yy, int *par) {
    int max[2] = {0, 0};
    int col = 0;
    char ***yy2 = NULL;
  	struct winsize wine;
    int y = 0;

    ioctl(1, 1074295912, &wine);
    y = par[6] > 1 ? par[6] : wine.ws_col;
    yy2 = (char***)malloc(sizeof(char***) * c);
    par[44] = c;
    calc_max(yy2, yy, max, par);
    col = calc_col( y, c, max, par);
    par[46] = col;
    print_table2(yy2, c, max, par);
    free(yy2);
}

static void calc_max(char ***yy2, char **yy, int *max, int *par) {
    int b = 0;
    int *titi = mx_make_titi(par[44], yy, par);
    struct stat u; 

    for (b = 0; b < par[44]; b++){
        yy2[b] = (char**)malloc(sizeof(char**)*3);
        lstat(yy[b], &u);
        par[45] = par[45] + u.st_blocks;
        yy2[b][0] = mx_itoa(u.st_blocks);
        par[46] = mx_strlen(yy2[b][0]);     
        max[0] = (par[46] > max[0]) ? par[46] : max[0];
        yy2[b][2] = mx_strdup(yy[b]);
        yy2[b][1] = mx_memrchr(yy[b], '/', mx_strlen(yy[b]));
        yy2[b][1] = yy2[b][1] == NULL || par[48]? mx_strdup(yy[b]) :
                    mx_strdup(&yy2[b][1][1]);
        par[46] = (max[0] + titi[b]) + 1;
        max[1] = (par[46] > max[1]) ? par[46] : max[1];
    }
    max[1] = (max[1] % 8 != 0) ? (max[1] / 8) * 8 + 8 : max[1] + 8; 
    free(titi);
}

static int calc_col(int y, int c, int *max, int *par) {
    int rest = 0;
    int col = 0;
    char *blocks = NULL;

    while(rest <= y && col < c) {
        col++;
        rest = col * max[1];
    } 
    col =  rest<= y ? col : col - 1;
    col = col < 1 || par[1] ? 1 : col;
    if (par[42]) {
        write(1, "total ", 6);
        blocks = mx_itoa(par[45]);
        write(1, blocks, mx_strlen(blocks));
        free(blocks);
        write(1, "\n", 1);
    }
    return col;
}

static void print_table2(char ***yy,int c, int *max, int *par) {
    int a = 0;
    int b = 0;
    int ind = 0;
    int col = par[46];
    int counter = (c % col) != 0 ? (c / col) +1 : c/col;
    struct stat u; 


    for (b = 0; b < counter; b++) {
        for (a = 0; a < col; a++) {
            ind = b + a * counter;
            if (ind < c) {
                lstat(yy[ind][2], &u);
                par[47] = par[25] && ((u.st_mode & MX_IFMT) == MX_IFDIR) ? 1 : 0;
                par[46] = a != col - 1 && (b + (a + 1) * counter < c);
                print_s(yy[ind], max, par);
            }
        }
        write(1, "\n",1);
    }
}

static void print_s(char **yy, int *max, int *par) {
    int flag = par[46];
    int tab = max[1] - (max[0] + 1 + mx_strlen(yy[1]));

    tab = par[47] ? max[1] - (max[0] + 1 + mx_strlen(yy[1]) + 1) : tab;
    par[46] = tab;
    for (int v  = mx_strlen(yy[0]); v < max[0]; v++)
        write(1," ",1);
    write(1,yy[0],mx_strlen(yy[0]));
    write(1," ",1);
    write(1,yy[1],mx_strlen(yy[1]));
    par[47] ? write (1, "/", 1) : 0;
    tab = tab % 8 == 0 ? tab / 8 - 1 : tab / 8;
    if ((tab - par[46]) < max[1] && flag)
        for (int st = 0; st <= tab; st++)
            write(1, "\t", 1);
    free(yy[0]);
    free(yy[1]);
    free(yy[2]);
    free(yy);
}
