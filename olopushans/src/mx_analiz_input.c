#include "uls.h"

static void alnaliz_input1(char **argv, int b, int c, int *par);

static void alnaliz_input2(char **argv, int b, int c, int *par);

static void alnaliz_input_end(int *par);

int *mx_analiz_input(int argc, char *argv[]) {
    int b = 0;
    int c = 0;
    int *par = (int*)malloc(sizeof(int*) * 49);

    for (b = 0; b < 41; b++)
        par[b] = 0;
    par[39] = argc + 1;
    par[41] = 1;
    for (b = 1; b < argc; b++){
        if (argv[b][0] == '-' && argv[b][1] != '\0') {
            for (c = 1; c < mx_strlen(argv[b]); c++)
                alnaliz_input1(argv, b, c, par);
        }
        else {
            par[39] = b;
            par[48] = 1;
            b = argc;
        }
    }
    alnaliz_input_end(par);
    return par;
}

static void alnaliz_input1(char **argv,int b, int c, int *par) {
    if (mx_memchr("ACRSTacfhlmnoprstu1",argv[b][c], 19) == NULL)
        mx_output_mistake2(argv,&argv[b][c], par);
    par[40] = 1;
    par[0] = argv[b][c] == '@' ? 1 : par[0];
    par[2] = argv[b][c] == 'A' ? 1 : par[2];
    par[3] = argv[b][c] == 'a' ? 1 : par[3];
    par[8] = argv[b][c] == 'd' ? 1 : par[8];
    par[9] = argv[b][c] == 'e' ? 1 : par[9];
    par[10] = argv[b][c] == 'F' ? 1 : par[10];
    par[12] = argv[b][c] == 'G' ? 1 : par[12];
    par[13] = argv[b][c] == 'g' ? 1 : par[13];
    par[14] = argv[b][c] == 'H' ? 1 : par[14];
    par[15] = argv[b][c] == 'h' ? 1 : par[15];
    par[16] = argv[b][c] == 'i' ? 1 : par[16];
    par[17] = argv[b][c] == 'k' ? 1 : par[17];
    par[22] = argv[b][c] == 'O' ? 1 : par[22];
    par[23] = argv[b][c] == 'o' ? 1 : par[23];
    par[25] = argv[b][c] == 'p' ? 1 : par[25];
    par[27] = argv[b][c] == 'R' ? 1 : par[27];
    alnaliz_input2(argv, b, c, par);
}

static void alnaliz_input2(char **argv,int b, int c, int *par) {
    par[28] = argv[b][c] == 'r' ? 1 : par[28];
    par[29] = argv[b][c] == 'S' ? 1 : par[29];
    par[30] = argv[b][c] == 's' ? 1 : par[30];
    par[31] = argv[b][c] == 'T' ? 1 : par[31];
    par[32] = argv[b][c] == 't' ? 1 : par[32];
    par[33] = argv[b][c] == 'u' ? 1 : par[33];
    par[34] = argv[b][c] == 'U'? 1 : par[34];
    par[35] = argv[b][c] == 'v' ? 1 : par[35];
    par[36] = argv[b][c] == 'W' ? 1 : par[36];
    par[38] = argv[b][c] == 'x' ? 1 : par[38];
    if (argv[b][c] == 'f') {
        par[3] = 1;
        par[11] = 1;
    }
    if (argv[b][c] == 'u') {
        par[7] = 0;
        par[33] = 1;
    }
    mx_analiz_input_second(argv, b, c, par);
}

static void alnaliz_input_end(int *par) {
    par[14] = (!par[10] && !par[8] && !par[19] && par[14]) ? par[14] : 0;
    par[0] = par[19] ? par[0] : 0;
    par[7] = (par[19] && par[32]) ? par[7] : 0;
    par[9] = par[19]  ? par[9] : 0;
    par[15] = par[19] ? par[15] : 0;
    par[22] = par[19] ? par[22] : 0;
    par[31] = par[19] ? par[31] : 0;
    if (!isatty(1)) {
        par[1] = !par[6] ? 1 : par[1];
        par[6] = par[6] || par [20]? 80 : par[6];
    }
    else
        par[6] = !par[1] ? 1 : par[6];
    par[41] = par[19] || par[20] || par[30] ? 0 : 1;
}
