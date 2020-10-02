#include <stdlib.h>
#include <stdint.h>
#include <ncurses.h>
#include "libs/wincfg.h"
#include "libs/winSetup.h"
#include "libs/getFiles.h"
#include "libs/showFiles.h"

int main(int argc, char **argv) {
    (void)argc; (void)argv;

    uint16_t ch;
    Wincfg_t *wincfg = winSetup();
    showFiles(wincfg->mainWincfg, getFiles("."));
    wrefresh(wincfg->mainWincfg->mainWin);

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
            showFiles(wincfg->mainWincfg, getFiles("."));
            wrefresh(wincfg->mainWincfg->mainWin);
        }
    }

    endwin();
    free(wincfg->mainWincfg);
    free(wincfg->cmdWincfg);
    free(wincfg);
    return 0;
}
