#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ncurses.h>
#include "libs/wincfg.h"
#include "libs/winSetup.h"
#include "libs/showFiles.h"
#include "libs/getCwd.h"

int main(int argc, char **argv) {
    (void)argv;

    uint16_t ch;
    Wincfg_t *wincfg = winSetup();
    if (argc>1) strcpy(wincfg->mainWincfg->currentDir, argv[1]);
    refresh();
    showFiles(wincfg->mainWincfg);
    box(wincfg->cmdWincfg->cmdWin, 0, 0);
    mvwprintw(wincfg->cmdWincfg->cmdWin, 0, 0, "Shell");
    wrefresh(wincfg->cmdWincfg->cmdWin);

    for (;;) {
        if ((ch = getch()) == ERR) {
            continue;
        }
        else if (ch == 'q') break;
        else {
            switch(ch) {
                case KEY_DOWN: {
                    if (wincfg->mainWincfg->selected != wincfg->mainWincfg->fileCount) wincfg->mainWincfg->selected++;
                    break;
                }
                case KEY_UP: {
                    if (wincfg->mainWincfg->selected != 0) wincfg->mainWincfg->selected--;
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
