#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <dirent.h>

char **getFiles(char *path) {
    struct dirent *entry;
    char **files = NULL;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        char *file = malloc(256);
        file = "NULL";
        files[0] = file;
    }
    else {
        for (uint16_t i=0; entry; i++) {
            entry = readdir(dir);
            char *file = malloc(256);
            file = entry->d_name;
            files[i] = entry->d_name;
        }
    }

    closedir(dir);
    return files;
}
