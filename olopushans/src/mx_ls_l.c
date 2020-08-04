#include "uls.h"

static void ls_l_files(char **files, int p, int pf, int *par);

static void ls_l_folders(char *folders, int f1, int f2, int *par);

static void ls_l_dop(char **yy, int c, int total,int *par);

static void print_time_l(struct stat u, int *par);

static char *print_time_l2(struct stat u, long int time_now, char *times_t);

void mx_ls_l(char **argv, int argc, int start, int *par) {
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
    ls_l_files( files, p, pf, par);
    if (pf >= 0) {
        for (a = 0; a <= pf; a++) {
            ls_l_folders(folders[a], pf != 0 || p != -1, a != 0 ||
            par[27] < 0, par);
            if (par[49] != 0)
                mx_output_mistake3(argv[0], folders[a], par); 
       }
    }   
    mx_free_array2(files, p + 1);
    mx_free_array2(folders,pf + 1);
}

static void ls_l_files(char **files, int p, int pf, int *par) {

    if (p >= 0 && par[27] >= 0) {
        ls_l_dop( files, p + 1, 0, par);
        if (pf >= 0)
            write(1,"\n",1);
    }
    par[48] = 0;
}

static void ls_l_folders(char *folders, int f1, int f2, int *par) {
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
            ls_l_dop(yy, c, 1, par);
            if (par[27] != 0) {
                par[27] = -1;
                mx_ls_l(yy, c, 0, par);
            }
        }
        mx_free_array2(yy,c);
    }
}

static void ls_l_dop(char **yy, int c, int total, int *par) {
    struct stat u;
    char *times = NULL;
    int b = 0;
    char *buf = NULL;
    int size[5] = { 0, 0, 0, 0, 0}; 
   
    par[42] = total;
    mx_print_total_l(yy, c, size, par);
    for (b = 0; b < c; b++){
        lstat(yy[b], &u);
        mx_ls_l2(u, yy[b], size, par);
        buf = mx_print_size_l(u, yy[b], size, par);
        print_time_l(u, par);
        times = mx_memrchr(yy[b], '/', mx_strlen(yy[b]));
        times==NULL || par[48] ? mx_printstr(yy[b]) : mx_printstr(&times[1]);
        ((u.st_mode & MX_IFMT) == MX_IFDIR) && par[25] ? write(1,"/", 1) : 0;
        if ((u.st_mode & MX_IFMT) == MX_IFLNK) {
            write(1, " -> ", 4);
            mx_printstr(buf);
        }
        write(1, "\n", 1);
        free(buf);
    }
}

static void print_time_l(struct stat u, int *par) {
    char *times = NULL;
    char *times_t = NULL;
    char *times_t2 = NULL;
    long int time_now = 0;

    time_now = time (NULL);
    times = ctime(par[33] ? &u.st_atime : &u.st_mtime);
    times_t = mx_memchr(times, ' ',mx_strlen(times));
    times_t = &times_t[1];
    if (!par[31]) 
        times_t = print_time_l2( u, time_now, times_t);
    else {
        times_t2 = mx_memrchr(times, '\n',mx_strlen(times));
        times_t2[0] = '\0';
    }
    mx_printstr(times_t);
    write(1," ", 1);
}

static char *print_time_l2(struct stat u, long int time_now, char *times_t) {
   char *times_t2 = NULL;

    if (time_now - u.st_mtime <= 15768000) {
        times_t2 = mx_memrchr(times_t,':',mx_strlen(times_t));
        times_t2[0]='\0';
    }
    else {
        times_t2 = mx_memchr(times_t,' ',mx_strlen(times_t));
        times_t2 = mx_memchr(&times_t2[1],' ',mx_strlen(&times_t2[1]));
        times_t2[1] = ' ';
        mx_strcpy(&times_t2[1], mx_memrchr(times_t,' ',mx_strlen(times_t)));
        times_t[mx_strlen(times_t) - 1] = '\0';
    }
    return times_t;
}
