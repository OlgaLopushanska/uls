#include "uls.h"

static void analiz_input_s1(char **argv,int b, int c, int *par);

static void analiz_input_s2(char **argv,int b, int c, int *par);

static void analiz_input_s3(char **argv,int b, int c, int *par);

static void analiz_input_s4(char **argv,int b, int c, int *par);

void mx_analiz_input_second(char **argv,int b, int c, int *par) {
    if (argv[b][c] == '1') {
        par[1] = 1;
        par[6] = 0;
        par[19] = 0;
        par[38] = 0;
    }
    if (argv[b][c] == 'C') {
        par[1] = 0;
        par[6] = 1;
        par[19] = 0;
        par[38] = 0;
    }
    if (argv[b][c] == 'l'){
        par[1] = 0;
        par[6] = 0;
        par[19] = 1;
        par[38] = 0;
    }
    analiz_input_s1(argv, b, c, par);
}

static void analiz_input_s1(char **argv,int b, int c, int *par) {
    if (argv[b][c] == 'x') {
        par[1] = 1;
        par[6] = 0;
        par[19] = 0;
        par[38] = 0;
    }
    if (argv[b][c] == 'B') {
        par[4] = 1;
        par[5] = 0;
        par[26] = 0;
        par[37] = 0;
    }
    if (argv[b][c] == 'b') {
        par[4] = 0;
        par[5] = 1;
        par[26] = 0;
        par[37] = 0;
    }
    analiz_input_s2(argv, b, c, par);
}

static void analiz_input_s2(char **argv,int b, int c, int *par) {
    if (argv[b][c] == 'q') {
        par[4] = 0;
        par[5] = 0;
        par[26] = 1;
        par[37] = 0;
    }
    if (argv[b][c] == 'w') {
        par[4] = 0;
        par[5] = 0;
        par[26] = 0;
        par[37] = 1;
    }
    if (argv[b][c] == 'c') {
        par[7] = 1;
        par[33] = 0;
    }
    analiz_input_s3(argv, b, c, par);
}

static void analiz_input_s3(char **argv,int b, int c, int *par) {
    if (argv[b][c] == 'H') {
        par[14] = 1;
        par[18] = 0;
        par[24] = 0;
    }
    if (argv[b][c] == 'L') {
        par[14] = 0;
        par[18] = 1;
        par[24] = 0;
    }
    if (argv[b][c] == 'P') {
        par[14] = 0;
        par[18] = 0;
        par[24] = 1;
    }
    analiz_input_s4(argv, b, c, par);
}

static void analiz_input_s4(char **argv,int b, int c, int *par) {
    if (argv[b][c] == 'm') {
        par[20] = 1;
        par[19] = 0;
    }
    if (argv[b][c] == 'n') {
        par[21] = 1;
        par[1] = 0;
        par[6] = 0;
        par[19] = 1;
        par[38] = 0;
    }
}
