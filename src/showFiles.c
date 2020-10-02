#include <stdint.h>
#include <ncurses.h>
#include "../libs/wincfg.h"

void showFiles(MainWincfg_t *win, char **files) {
    for (uint16_t i=0; files[i]; i++) {
        // if (i == win->h) return;
        mvwprintw(win->mainWin, i+1, 1, "%s", files[i]);
    }
}
