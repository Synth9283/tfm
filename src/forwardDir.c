#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <dirent.h>
#include "libs/wincfg.h"
#ifdef unix
#define DIRPATH '/'
#elif WIN32
#define DIRPATH '\\'
#endif

void forwardDir(MainWincfg_t *win) {
    if (!win->files[win->selected]) return;
    char *tmpDir = malloc(UINT16_MAX);
    strcpy(tmpDir, win->currentDir);
    uint16_t tmpLen = strlen(tmpDir);
    tmpDir[tmpLen+1] = '\0';
    if (strcmp(tmpDir, "/") || strcmp(tmpDir, "C:\\")) tmpDir[tmpLen] = DIRPATH;
    strcat(tmpDir, win->files[win->selected]);
    DIR *dir = opendir(tmpDir);

    if (dir) {
        strcpy(win->currentDir, tmpDir);
        win->fileCount = 0;
        win->offset = 0;
        win->selected = 0;
    }
    closedir(dir);
    free(tmpDir);
}
