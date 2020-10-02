#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <dirent.h>

char **getFiles(char *path) {
    struct dirent *entry = NULL;
    char **files = malloc(255);
    DIR *dir = opendir(path);

    if (dir == NULL) {
        char *file = malloc(1);
        file = '\0';
        files[0] = file;
    }
    else {
        uint8_t line = 0;
        for (uint16_t i=0; ((entry = readdir(dir)) != NULL);) {
            if (strcmp(".", entry->d_name)) {
                char *file = malloc(strlen(entry->d_name));
                strcpy(file, entry->d_name);
                files[i] = file;
                i++;
                line++;
            }
            else {
                i--;
                line--;
            }
        }
        char *file = malloc(1);
        file = '\0';
        files[line] = file;
    }

    closedir(dir);
    return files;
}
