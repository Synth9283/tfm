#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#ifdef unix
#include <ncurses.h>
#elif WIN32
#include <ncursesw/curses.h>
#endif
#include "libs/wincfg.h"
#include "libs/winSetup.h"
#include "libs/getFiles.h"
#include "libs/showFiles.h"
#include "libs/getCwd.h"
#include "libs/backDir.h"
#include "libs/forwardDir.h"

int main(int argc, char **argv) {
    (void)argv;

    uint16_t ch;
    Wincfg_t *wincfg = winSetup();
    if (argc>1) strcpy(wincfg->mainWincfg->currentDir, argv[1]);
    refresh();
    getFiles(wincfg->mainWincfg);
    showFiles(wincfg->mainWincfg);
    box(wincfg->cmdWincfg->cmdWin, 0, 0);
    mvwprintw(wincfg->cmdWincfg->cmdWin, 0, 0, "Shell");
    wrefresh(wincfg->cmdWincfg->cmdWin);

    for (;;) {
        if ((ch = getch()) == ERR) continue;
        else if (ch == 'q') break;
        else {
            switch(ch) {
                case KEY_DOWN: {
                    if (wincfg->mainWincfg->selected != wincfg->mainWincfg->fileCount) wincfg->mainWincfg->selected++;
                    if (!((wincfg->mainWincfg->selected-wincfg->mainWincfg->offset)%(wincfg->mainWincfg->h-2)) && (wincfg->mainWincfg->selected != wincfg->mainWincfg->fileCount)) wincfg->mainWincfg->offset++;
                    break;
                }
                case KEY_UP: {
                    if (wincfg->mainWincfg->selected != 0) wincfg->mainWincfg->selected--;
                    if (((wincfg->mainWincfg->selected-wincfg->mainWincfg->offset) == -1) && wincfg->mainWincfg->offset) wincfg->mainWincfg->offset--;
                    break;
                }
                case KEY_LEFT: {
                    backDir(wincfg->mainWincfg);
                    getFiles(wincfg->mainWincfg);
                    break;
                }
                case KEY_RIGHT: {
                    forwardDir(wincfg->mainWincfg);
                    getFiles(wincfg->mainWincfg);
                    break;
                }
                default: break;
            }
            showFiles(wincfg->mainWincfg);
        }
    }

    endwin();
    free(wincfg->mainWincfg->currentDir);
    free(wincfg->mainWincfg);
    free(wincfg->cmdWincfg);
    free(wincfg);
    return 0;
}
