#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <dirent.h>
#include "../libs/wincfg.h"

void forwardDir(MainWincfg_t *win) {
    if (!win->files[win->selected]) return;
    char *tmpDir = malloc(UINT16_MAX);
    strcpy(tmpDir, win->currentDir);
    uint16_t tmpLen = strlen(tmpDir);
    tmpDir[tmpLen+1] = '\0';
    if (tmpLen != 1) tmpDir[tmpLen] = '/';
    strcat(tmpDir, win->files[win->selected]);
    DIR *dir = opendir(tmpDir);

    if (dir) {
        strcpy(win->currentDir, tmpDir);
        win->selected = 0;
        win->offset = 0;
    }
    closedir(dir);
    free(tmpDir);
}
