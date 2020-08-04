#include "uls.h"

int mx_max_group(struct group *i, struct stat u) {
    char *times = NULL;
    int bb = 0;

    if ((i) != NULL) {
        times = i->gr_name;
        bb = mx_strlen(times);
     }
    else {
        times = mx_itoa(u.st_gid);
        bb = mx_strlen(times);
        free(times);
    }
    return bb;
}
