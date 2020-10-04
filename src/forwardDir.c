#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "../libs/wincfg.h"

void forwardDir(MainWincfg_t *win) {
    char *tmpDir = malloc(UINT16_MAX);
    strcpy(tmpDir, win->currentDir);
    tmpDir[strlen(tmpDir)+1] = '\0';
    tmpDir[strlen(tmpDir)] = '/';
    strcat(tmpDir, win->files[win->selected]);
    DIR *dir = opendir(tmpDir);

    if (dir != NULL) {
        strcpy(win->currentDir, tmpDir);
        win->selected = 0;
    }
    closedir(dir);
    free(tmpDir);
}
