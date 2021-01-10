#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <dirent.h>
#include "../libs/wincfg.h"

void getFiles(MainWincfg_t *win) {
    for (uint16_t i=0; !win->fileCount && i<win->fileCount; i++) {
        free(win->files[i]);
    }
    struct dirent *entry = NULL;
    DIR *dir = opendir(win->currentDir);

    if (!dir) win->files[0] = '\0';
    else {
        win->fileCount = 0;
        for (uint16_t i=0; ((entry = readdir(dir)) != NULL);) {
            if (strcmp(".", entry->d_name) && strcmp("..", entry->d_name)) {
                char *file = malloc(entry->d_reclen);
                strcpy(file, entry->d_name);
                win->files[i] = file;
                i++;
                win->fileCount++;
            }
        }
        win->files[win->fileCount] = '\0';
        win->fileCount--;
    }
    closedir(dir);
}
