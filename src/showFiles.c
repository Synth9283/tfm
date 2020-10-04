#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ncurses.h>
#include "../libs/wincfg.h"

void showFiles(MainWincfg_t *win) {
    box(win->mainWin, 0, 0);
    mvwprintw(win->mainWin, 0, 0, win->currentDir);
    for (uint16_t i=0; win->files[i]; i++) {
        // if (i == win->h) return;
        if (i==win->selected) {
            wattron(win->mainWin, A_REVERSE);
            mvwprintw(win->mainWin, i+1, 1, "%s", win->files[i]);
            wattroff(win->mainWin, A_REVERSE);
        }
        else mvwprintw(win->mainWin, i+1, 1, "%s", win->files[i]);
    }
    wrefresh(win->mainWin);
}
