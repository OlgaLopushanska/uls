#include "uls.h"

static void ls_standart_folders(char *folders, int f1, int f2, int *par);

static void ls_standart_files(char **files, int p, int pf, int *par);

static void ls_stf_R(char *folders, int f1, int f2, int *par);

int mx_standart_ls_links(char **argv, int argc, int start, int *par) {
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
    ls_standart_files( files, p, pf, par);
    if (pf >= 0) {
        for (a = 0; a <= pf; a++) {
            ls_standart_folders(folders[a], pf != 0
            || p != -1, a != 0 || par[27] < 0, par);
            if (par[49] != 0)
                mx_output_mistake3(argv[0], folders[a], par);
        }
    }    
    mx_free_array2(folders,pf + 1);
    return 1; 
}

static void ls_standart_files(char **files, int p, int pf, int *par) {
    int *titi = NULL;

    if(p >= 0 && par[27] >= 0) {
        titi = mx_make_titi(p+1, files, par);
        mx_print_table( p+1, titi, files, par);
        if(pf >= 0)
            write(1,"\n",1);
    }
    mx_free_array2(files, p + 1);
    par[48] = 0;
}

static void ls_standart_folders(char *folders, int f1, int f2, int *par) {
    char *n = NULL;
    int flag = 0;

    n = (n = mx_memrchr(folders, '/', mx_strlen(folders))) ? &n[1] : folders;
    flag = (n[0] == '.' && n[1] == '\0') || (n[0] == '.' && n[1] == '.') ;
    if(par[27] >= 0 || (par[27] < 0 && !flag))
        ls_stf_R( folders, f1, f2, par);
}    

static void ls_stf_R(char *folders, int f1, int f2, int *par) {
    char **yy = NULL;
    int c = 0;
    int *titi = NULL;

    if (f1 || par[27] < 0) {
        f2 ? write(1,"\n",1) : f2;
        write(1, folders, mx_strlen(folders));
        write(1,":\n",2);
    }
    yy = mx_read_folder(&c, folders, par);
    if (yy != NULL) {
        titi = mx_make_titi(c, yy, par);
        mx_print_table( c, titi, yy, par);
        if (par[27] != 0) {
            par[27] = -1;
            mx_standart_ls_links(yy, c, 0, par);
        }
    }
    mx_free_array2(yy, c);
}

