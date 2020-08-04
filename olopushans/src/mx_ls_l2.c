#include "uls.h"

static void print_mode(int mode, int *par);

static void print_mode2(int mode, char *yy, struct stat u);

static void print_mode3(struct stat u, int *size, int *par);

void mx_ls_l2(struct stat u, char *yy, int *size, int *par) {
    char *buf = NULL;

    print_mode(u.st_mode & MX_IFMT, par);
    print_mode2( u.st_mode & ~ MX_IFMT, yy, u);
    buf = mx_itoa(u.st_nlink);
    mx_print_colum(size[2], mx_strlen(buf), u.st_nlink, NULL);
    free(buf);
    print_mode3( u, size, par);

}

static void print_mode(int mode, int *par){
    int res = 0;

    res = (mode == MX_IFREG) ? write(1,"-",1) : 0;
    res = (mode == MX_IFDIR) ? write(1,"d",1) : 0;
    res = (mode == MX_IFCHR) ? write(1,"c",1) : 0;
    par[15] = (mode == MX_IFCHR) ? 0 : par[15];
    res = (mode == MX_IFBLK) ? write(1,"b",1) : 0;
    res = (mode == MX_IFLNK) ? write(1,"l",1) : 0;
    res = (mode == MX_IFIFO) ? write(1,"p",1) : 0;
    res = (mode == MX_IFSOCK) ? write(1,"s",1) : 0;
}

static void print_mode2(int mode, char *yy, struct stat u) {
    (mode & MX_IRUSR) ? mx_printstr("r") : mx_printstr("-");
    (mode & MX_IWUSR) ? mx_printstr("w") : mx_printstr("-");
    (mode & MX_ISUID) ? mx_printstr("s") : 
    ((mode & MX_IXUSR) ? mx_printstr("x") : mx_printstr("-"));
    (mode & MX_IRGRP) ? mx_printstr("r") : mx_printstr("-");
    (mode & MX_IWGRP) ? mx_printstr("w") : mx_printstr("-");
    (mode & MX_ISGID) ? mx_printstr("s") : 
    ((mode & MX_IXGRP)  ? mx_printstr("x") : mx_printstr("-"));
    (mode & MX_IROTH) ? mx_printstr("r") : mx_printstr("-");
    (mode & MX_IWOTH) ? mx_printstr("w") : mx_printstr("-");
    (mode & MX_ISVTX) ? mx_printstr("t") : 
    ((mode & MX_IXOTH) ? mx_printstr("x") : mx_printstr("-"));
    (listxattr(yy, NULL, 0, 0x0001) > 0) ? mx_printstr("@") :
    ((acl_get_file(yy, 0x0000010) != NULL && ((u.st_mode & 0170000) != 0120000)) ?
        mx_printstr("+") : mx_printstr(" "));
    mx_printstr(" "); 
}

static void print_mode3(struct stat u, int *size, int *par) {
    struct passwd *t = NULL;
    struct group *i = NULL;
    char* times = NULL;

    if (!par[21]) {
        t  = getpwuid(u.st_uid);
        if(t != NULL)
            mx_print_colum(-(size[0] + 2), mx_strlen(t->pw_name), 0, t->pw_name);
        i = getgrgid(u.st_gid);
        times = (i != NULL) ? i->gr_name : mx_itoa(u.st_gid);
        if (!par[23])
            mx_print_colum(- (size[1] + 2), mx_max_group(i, u), 0, times);
        if (i == NULL) 
        free(times);
    }
    else {
        times = mx_itoa(u.st_uid);
        mx_print_colum(-(size[0] + 2), mx_strlen(times), 0, times);
        free(times);
        times = mx_itoa(u.st_gid);
        if (!par[23])
            mx_print_colum(- (size[1] + 2), mx_strlen(times), 0, times);
        free(times);
    }
}
