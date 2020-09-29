#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <dirent.h>

char **getFiles(char *path) {
    struct dirent *entry = NULL;
    char **files = malloc(256*30);
    DIR *dir = opendir(path);

    if (dir == NULL) {
        char *file = malloc(5);
        file = "NULL";
        files[0] = file;
    }
    else {
        for (uint16_t i=0; ((entry = readdir(dir)) != NULL); i++) {
            entry = readdir(dir);
            files[i] = entry->d_name;
        }
    }

    closedir(dir);
    return files;
}
