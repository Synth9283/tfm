#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ncurses.h>
#include "../libs/wincfg.h"
#include "../libs/getFiles.h"

void showFiles(MainWincfg_t *win, char *dir) {
    char **files = getFiles(dir);
    box(win->mainWin, 0, 0);
    mvwprintw(win->mainWin, 0, 0, dir);
    win->fileCount = 0;
    for (uint16_t i=0; files[i]; i++, win->fileCount++) {
        // if (i == win->h) return;
        if (i==win->selected) {
            wattron(win->mainWin, A_REVERSE);
            mvwprintw(win->mainWin, i+1, 1, "%s", files[i]);
            wattroff(win->mainWin, A_REVERSE);
        }
        else mvwprintw(win->mainWin, i+1, 1, "%s", files[i]);
        free(files[i]);
    }
    win->fileCount--;
    wrefresh(win->mainWin);
}
