#include "uls.h"

static void ls_m_files(char **files, int p, int pf, int *par);

static void ls_m_folders(char *folders, int f1, int f2, int *par);

void mx_ls_m(char **argv, int argc, int start, int *par) {
    char **folders = NULL;
    char **files = NULL;
    int p = start;
    int pf = argc;
    int a = 0;

    par[44] = p;
    par[45] = pf;
    files = mx_generate_input(argv, &folders, par);
    p = par[44];
    pf = par[45];
    ls_m_files(files, p, pf, par);
    if (pf >= 0) {
        for (a = 0; a <= pf; a++) {
            ls_m_folders(folders[a], pf != 0 || p != -1, a != 0
            || par[27] < 0, par);
            if (par[49] != 0)
                mx_output_mistake3(argv[0], folders[a], par);
        }
    }        
    mx_free_array2(files, p + 1);
    mx_free_array2(folders,pf + 1);
}

static void ls_m_files(char **files, int p, int pf, int *par){
    if (p >= 0 && par[27] >= 0) {
        mx_print_m(p + 1, files, par);
        if (pf >= 0)
            write(1,"\n",1);
    }
    par[48] = 0;
}

static void ls_m_folders(char *folders, int f1, int f2, int *par) {
    char *n = NULL;
    int flag = 0;
    char **yy = NULL;
    int c = 0;

    n = (n = mx_memrchr(folders, '/', mx_strlen(folders))) ? &n[1] : folders;
    flag = (n[0] == '.' && n[1] == '\0') || (n[0] == '.' && n[1] == '.');
    if (par[27] >= 0 || (par[27] < 0 && !flag)) {
        if (f1 || par[27] < 0) {
            f2 ? write(1,"\n",1) : f2;
            write(1, folders, mx_strlen(folders));
            write(1,":\n",2);
        }
        yy = mx_read_folder(&c, folders, par);
        if (yy != NULL) {
            mx_print_m(c, yy, par);
            if (par[27] != 0) {
                par[27] = -1;
                mx_ls_m(yy, c, 0, par); 
            }
        }
        mx_free_array2(yy,c);
    }
}
