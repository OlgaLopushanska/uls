#include "uls.h"

int mx_free_list(t_list *list) {
    if (list == NULL)
        return 0;
    t_list *tempor = list;
    
    while (list->next != NULL) {
        tempor = list;
        list = list->next;
        free(tempor);
    }
    free(list);
    return 1;
}
