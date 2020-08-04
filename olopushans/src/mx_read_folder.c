#include "uls.h"

static t_list *read_list(DIR *r);

static char **names_array(char *path, t_list *consis, int *c, int *par);

char **mx_read_folder(int *c, char *path, int *par) {
    char **yy = NULL;
    t_list *consis = NULL;
    DIR *r = NULL;

    r = opendir(path);
    if (r != NULL) {
        consis = read_list(r);
        *c = mx_list_size(consis);
        yy = names_array(path,consis, c, par);
        closedir(r);
        if (!par[11])
            mx_sorting(yy, *c, par);
    }
    else 
        par[49] = errno;
    return yy;
}

static t_list *read_list(DIR *r) {
    struct dirent *e = NULL;
    t_list *consis = NULL;

    e = readdir(r);
    while (e != NULL) {
        mx_push_back(&consis, mx_strdup(e->d_name));
        e = readdir(r);
    }
    return consis;
}

static char **names_array(char *path, t_list *consis, int *c, int *par) {
    char** yy= (char**)malloc (sizeof(char**) * (*c));
    char *te = NULL;
    int a = -1;
    int b = 0;
    t_list *temp = NULL;
    char *n = NULL;

    temp = consis;
    te = (path[mx_strlen(path) - 1] == '/') ? mx_strdup(path)
        : mx_strjoin(path, "/");
    for (b = 0; b < *c; b++) {
        n = (char*)(consis->data);
        if ((par[3]) || (par[2] && !((n[0] == '.' && n[1] == '\0')
            || (n[0] == '.' && n[1] == '.'))) || (n[0] != '.')) {
            a++;
            yy[a]  = mx_strjoin(te, (char *)(consis->data));
        }
        free(consis->data);
        consis = consis->next;
    }   
    mx_free_list(temp) ;
    free(te);
    *c = a + 1 ;
    return yy;
}
