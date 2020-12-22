#include <stdint.h>
#include <string.h>
#include "../libs/wincfg.h"
#include "../libs/getFiles.h"

void backDir(MainWincfg_t *win) {
    if (strlen(win->currentDir) == 1) return;
    else {
        win->selected = 0;
        win->offset = 0;
        for (uint16_t i=strlen(win->currentDir); i>0; i--) {
            if (win->currentDir[i] != '/') win->currentDir[i] = '\0';
            else {
                win->currentDir[i] = '\0';
                return;
            }
        }
    }
}
