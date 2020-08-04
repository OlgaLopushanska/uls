#include "uls.h"

static int bubble(char **arr, int size,int *par);

static long *make_array(char **path, int c, int *par);

static int bubble_sort_struct(long *arr, char **urr, int size);

int mx_sorting(char **arr, int size, int *par) {
    int y = 0;
    long *urr = NULL;

    if (par[28])
        y = bubble( arr, size, par);
    else if (par[7] || par[29] || par[32]) {
        urr = make_array(arr, size, par);
        y = bubble_sort_struct(urr, arr, size);
        free(urr);
    }
    else 
        y = bubble( arr, size, par);
    return y;
}

static int bubble(char **arr, int size,int *par) {
    int y = 0;
    int cmp = 0;

    for (int b = 0; b < size; b++) {
        for (int a = 0; a < size - 1; a++) {
            cmp = par[28] == 0 ? mx_strcmp(arr[a], arr[a + 1])
            : mx_strcmp(arr[a + 1], arr[a]);
            if (cmp > 0) {
                char *k = arr[a];
                
                arr[a] = arr[a + 1];
                arr[a + 1] = k;
                y++;
            }
        }
    }
    return y;
}

static long *make_array(char **path, int c, int *par) {
    long *array = NULL;
    struct stat u;
    int a = 0;
    
    array = (long*)malloc (sizeof(long*) * (c));
    for(; a < c; a++){
        lstat(path[a], &u);
        if(par[7])
            array[a] = u.st_ctime;
        if(par[32])
            array[a] = par[33] ? u.st_atime : u.st_mtime;
        if(par[29])
            array[a] = u.st_size;
    }
    return array;
}

static int bubble_sort_struct(long *arr, char **urr, int size) {
    int y = 0;
    long t = 0;
    char *k = NULL;

    for (int b = 0; b < size; b++) {
        for (int a = 0; a < size - 1; a++) {
            if (arr[a] < arr[a + 1]) {
                k = urr[a];
                t = arr[a];
                arr[a] = arr[a + 1];
                urr[a] = urr[a + 1];
                arr[a + 1] = t;
                urr[a + 1] = k;
                y++;
            }
        }
    }
    return y;
}
