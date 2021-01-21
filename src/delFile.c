#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "../libs/wincfg.h"

void delFile(MainWincfg_t *win) {
    if (!win->files[win->selected]) return;
    DIR *dir = opendir(win->files[win->selected]);
    
    if (!dir) {
        free(win->status);
        win->status = malloc(strlen(win->files[win->selected])+9);
        strcpy(win->status, win->files[win->selected]);
        strcat(win->status, " deleted!");
        remove(win->files[win->selected]);
    }

    closedir(dir);
}
