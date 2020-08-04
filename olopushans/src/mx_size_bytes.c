#include "uls.h"

static float rounding(float in, int sign);

static char *byte1(float data, char *res, int *a);

char *mx_size_bytes(int size) {
    float data = (float)size;
    int a = 0;
    int b = 0;
    char *res = mx_strnew(6);

    res = byte1( data, res, &a);
    b = mx_strlen(res);
    if (a == 0)
        res[b] = 'B';
    else if (a == 1)
        res[b] = 'K';
    else if (a == 2)
        res[b] = 'M';
    else if (a == 3)
        res[b] = 'G';
    return res;
}

static float rounding(float in, int sign) {
    float out = in;
    float b = 0;
    
    if(sign == 0){
        b = (in * 10.0 - (float)((int)in * 10));
        if((int)b > 4)
            out = out + 1.0;
    }
    if(sign == 1){
        in = in * 10.0;
        b = (in * 10.0 - (float)((int)in * 10));
        if((int)b > 4){
            out = out * 10.0 + 1.0;
            out = out / 10.0;
        }
    }
    return out;
}

static char *byte1(float data, char *res, int *a){
    char *str = NULL;

    for (*a = 0; data > 999.; (*a)++)
        data = data / 1024.;
    if (data > 9.94|| *a == 0) {
        data = rounding(data, 0);
        str = mx_itoa((int)data); 
        mx_strcpy(res, str);
        free(str);   
    }
    else{ 
        data = rounding(data, 1);
        res[0] = ((int)data) + 48;
        res[1] = '.';
        data = data * 10.0 - (float)((int)data * 10);
        res[2] = (int)data + 48;
    }
    return res;
}
