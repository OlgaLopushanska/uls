#include "uls.h"

 void mx_free_array2(char **arr, int row) {
    if (arr) {
        for (int a = 0; a < row; a++) {
            if( arr[a]) {
                free(arr[a]);
                arr[a] = NULL;
            }
        }
        free(arr);
        arr = NULL;
    }
}
