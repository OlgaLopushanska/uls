#include "uls.h"

static void ls_s_folders(char *folders, int f1, int f2, int *par);

static void ls_s_files(char **files, int p, int pf, int *par);

static void ls_sf_R(char *folders, int f1, int f2, int *par);

int mx_ls_s(char **argv, int argc, int start, int *par) {
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
    ls_s_files( files, p, pf, par);
    if(pf >= 0) {
        for(a = 0; a <= pf; a++) {
            ls_s_folders(folders[a], pf != 0
            || p != -1, a != 0 || par[27] < 0, par);
            if(par[49] != 0)
                mx_output_mistake3(argv[0], folders[a], par);
        }
    }        
    mx_free_array2(folders,pf + 1);
    return 1; 
}

static void ls_s_files(char **files, int p, int pf, int *par) {

    if (p >= 0 && par[27] >= 0) {
        par[42] = 0;
        mx_print_table_s( p+1, files, par);
        if (pf >= 0)
            write(1,"\n",1);
    }
    mx_free_array2(files, p + 1);
    par[48] = 0;
}

static void ls_s_folders(char *folders, int f1, int f2, int *par) {
    char *n = NULL;
    int flag = 0;

    n = (n = mx_memrchr(folders, '/', mx_strlen(folders))) ? &n[1] : folders;
    flag = (n[0] == '.' && n[1] == '\0') || (n[0] == '.' && n[1] == '.');
    if (par[27] >= 0 || (par[27] < 0 && !flag))
       ls_sf_R( folders, f1, f2, par);
}    

static void ls_sf_R(char *folders, int f1, int f2, int *par) {
    char **yy = NULL;
    int c = 0;

    if (f1 || par[27] < 0) {
        f2 ? write(1,"\n",1) : f2;
        write(1, folders, mx_strlen(folders));
        write(1,":\n",2);
    }
    yy = mx_read_folder(&c, folders, par);
    if (yy != NULL) {
        par[42] = 1;
        mx_print_table_s( c, yy, par);
        if (par[27] != 0) {
            par[27] = -1;
            mx_ls_s(yy, c, 0, par); 
        }
    }
    mx_free_array2(yy, c);
}
