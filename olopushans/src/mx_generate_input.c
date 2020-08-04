#include "uls.h"

char **mx_generate_input(char **argv, char ***folders, int *par) {
    char **files = NULL;
    int a = par[44];
    int argc = par[45];
    struct stat u;
    int res = 0;

    if (!par[11])
        mx_sorting(&argv[par[44]], par[45] - par[44], par);
    files   = (char**)malloc(sizeof(char**) * (argc));
    *folders = (char**)malloc(sizeof(char**) * (argc));
    par[44] = -1;
    par[45] = -1;
    for (; a < argc; a++) {
        res = lstat(argv[a], &u);
        if(res < 0)
            mx_output_mistake1(argv[0], argv[a], par);
        else {
            if ((u.st_mode & MX_IFMT) == MX_IFDIR) {
                (*folders)[++(par[45])] = mx_strdup(argv[a]);
            }
            else
                files[++(par[44])] = mx_strdup(argv[a]);
        }
    }
    return files;

}
