#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "../libs/wincfg.h"

void delFile(MainWincfg_t *win) {
    if (!win->files[win->selected]) return;
    DIR *dir = opendir(win->files[win->selected]);

    if (!dir) {
        free(win->status);
        int8_t delStatus = remove(win->files[win->selected]);
        if (!delStatus) {
            win->status = malloc(strlen(win->files[win->selected])+9);
            strcpy(win->status, win->files[win->selected]);
            strcat(win->status, " deleted");
        }
        else {
            win->status = malloc(strlen(win->files[win->selected])+18);
            strcpy(win->status, "Failed to delete ");
            strcat(win->status, win->files[win->selected]);
        }
    }
    else {
        win->status = malloc(strlen(win->files[win->selected])+16);
        strcpy(win->status, win->files[win->selected]);
        strcat(win->status, " is a directory");
    }

    closedir(dir);
}
