#include "uls.h"

int main(int argc, char *argv[]) {
    int *par = NULL;
    int res = 0;
    char *path = "./";
    int out = 0;
 
    par = mx_analiz_input(argc, argv);
    res = (par[41] == 1 && par[39] > argc) ?
          mx_standart_ls_links(&path, 1, 0, par) : res;
    res = (par[41] == 1 && par[39] < argc) ?
          mx_standart_ls_links(argv, argc, par[39], par) : res;
    if (par[40]) {
        if (par[19])
            par[39] > argc ? mx_ls_l(&path, 1, 0, par) :
            mx_ls_l(argv, argc, par[39], par);
        if (par[20])
            par[39] > argc ? mx_ls_m(&path, 1, 0, par) :
            mx_ls_m(argv, argc, par[39], par);
        if (par[30])
            par[39] > argc ? mx_ls_s(&path, 1, 0, par) :
            mx_ls_s(argv, argc, par[39], par);
    }
    out = par[43];
    free(par);
    return out;
}
