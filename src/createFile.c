#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "../libs/wincfg.h"

void createFile(MainWincfg_t *win) {
    free(win->status);
    FILE *fptr = fopen(win->fileName, "w");
    fclose(fptr);

    if (fptr) {
        win->status = malloc(strlen(win->fileName)+9);
        strcpy(win->status, win->fileName);
        strcat(win->status, " created");
    }
    else {
        win->status = malloc(strlen(win->fileName)+18);
        strcpy(win->status, "Failed to create ");
        strcat(win->status, win->fileName);
    }
}
