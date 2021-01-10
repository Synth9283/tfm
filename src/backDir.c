#include <stdint.h>
#include <string.h>
#include "../libs/wincfg.h"
#include "../libs/getFiles.h"
#ifdef unix
#define DIRPATH '/'
#elif _WIN32
#define DIRPATH '\\'
#endif

void backDir(MainWincfg_t *win) {
    if (strcmp(win->currentDir, "/") && strcmp(win->currentDir, "C:")) return;
    else {
        win->selected = 0;
        win->offset = 0;
        for (uint16_t i=strlen(win->currentDir); i>0; i--) {
            if (win->currentDir[i] != DIRPATH) win->currentDir[i] = '\0';
            else {
                win->currentDir[i] = '\0';
                return;
            }
        }
    }
}
