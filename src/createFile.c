#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "../libs/wincfg.h"

void createFile(MainWincfg_t *win) {
    free(win->status);
    FILE *fptr = fopen(win->fileName, "w");

    if (!fptr) {
        win->status = malloc(strlen(win->files[win->selected])+9);
        strcpy(win->status, win->files[win->selected]);
        strcat(win->status, " deleted");
    }
    else {
        win->status = malloc(strlen(win->files[win->selected])+18);
        strcpy(win->status, "Failed to create ");
        strcat(win->status, win->files[win->selected]);
    }
}
