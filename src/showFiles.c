#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#ifdef unix
#include <ncurses.h>
#elif _WIN32
#include <ncursesw/curses.h>
#endif
#include "../libs/wincfg.h"

void showFiles(MainWincfg_t *win) {
    wclear(win->mainWin);
    box(win->mainWin, 0, 0);
    mvwprintw(win->mainWin, 0, 0, win->currentDir);
    for (uint16_t i=0; win->files[i+win->offset]; i++) {
        if (i+win->offset==win->selected) {
            wattron(win->mainWin, A_REVERSE);
            mvwprintw(win->mainWin, i+1, 1, "%s", win->files[i+win->offset]);
            wattroff(win->mainWin, A_REVERSE);
        }
        else mvwprintw(win->mainWin, i+1, 1, "%s", win->files[i+win->offset]);
        if (i == win->h-3) break;
    }
    wrefresh(win->mainWin);
}
