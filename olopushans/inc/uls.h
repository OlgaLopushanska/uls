#ifndef  ULS_H
#define  ULS_H

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include "./libmx/inc/libmx.h"

#define MX_IFMT 0170000
#define MX_IFDIR 0040000
#define MX_IFCHR 0020000
#define MX_IFBLK 0060000
#define MX_IFREG 0100000
#define MX_IFIFO 0010000
#define MX_IFLNK 0120000
#define MX_IFSOCK 0140000
#define MX_IRUSR 0400
#define MX_IWUSR 0200
#define MX_IXUSR 0100
#define MX_IRGRP 040
#define MX_IWGRP 020
#define MX_IXGRP 010
#define MX_IROTH 04
#define MX_IWOTH 02
#define MX_IXOTH 01
#define MX_ISUID 04000
#define MX_ISGID 02000
#define MX_ISVTX 01000

void mx_ls_l(char **argv, int argc, int start, int *par);

int mx_standart_ls_links(char **argv, int argc, int start, int *par);

int *mx_analiz_input(int argc, char *argv[]);

int *mx_make_titi(int c, char **yy, int *par);

void mx_output_mistake1(char *m, char *u, int *par);

void mx_free_array2(char **arr, int row);

void mx_print_table(int c, int *titi, char **yy, int *par);

void mx_write_zero(char *st);

char **mx_read_folder(int *c, char *path, int *par);

int mx_free_list(t_list *list);

void mx_analiz_input_second(char **argv,int b, int c, int *par);

void mx_output_mistake2(char **argv,char *sign, int *par);

char *mx_convert_to_hex(int num);

char **mx_generate_input(char **argv, char ***folders, int *par);

void mx_ls_l2(struct stat u, char *yy, int *size, int *par);

void mx_print_colum(int size, int len, int data, const char *ch);

int mx_max_group(struct group *i, struct stat u);

void mx_print_total_l(char **yy, int c, int *size, int *par);

char *mx_print_size_l(struct stat u, char *yy, int *size, int *par);

void mx_ls_m(char **argv, int argc, int start, int *par);

void mx_print_m(int y, char **yy, int *par);

void mx_print_table_s(int c, char **yy, int *par);

int mx_ls_s(char **argv, int argc, int start, int *par);

char *mx_size_bytes(int size);

int mx_sorting(char **arr, int size, int *par);

void mx_output_mistake3(char *m, char *u, int *par);

#endif
