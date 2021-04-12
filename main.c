#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#ifdef unix
#include <ncurses.h>
#elif WIN32
#include <ncursesw/curses.h>
#endif
#include "src/libs/wincfg.h"
#include "src/libs/winSetup.h"
#include "src/libs/getFiles.h"
#include "src/libs/showFiles.h"
#include "src/libs/getCwd.h"
#include "src/libs/backDir.h"
#include "src/libs/forwardDir.h"
#include "src/libs/delFile.h"
#include "src/libs/createFile.h"
#include "src/libs/getInput.h"

int main(int argc, char **argv) {
    (void)argv;

    uint16_t ch;
    Wincfg_t *wincfg = winSetup();
    if (argc>1) strcpy(wincfg->mainWincfg->currentDir, argv[1]);
    refresh();
    getFiles(wincfg->mainWincfg);
    strcpy(wincfg->mainWincfg->status, "Select");
    showFiles(wincfg->mainWincfg);
    box(wincfg->cmdWincfg->cmdWin, 0, 0);
    mvwprintw(wincfg->cmdWincfg->cmdWin, 0, 0, "Shell");
    wrefresh(wincfg->cmdWincfg->cmdWin);

    for (;;) {
        if ((ch = getch()) == ERR) continue;
        else if (ch == 'q') break;
        else {
            if (!wincfg->mainWincfg->getInput) {
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
                    case KEY_ENTER:
                    case 10:
                    case KEY_RIGHT: {
                        forwardDir(wincfg->mainWincfg);
                        getFiles(wincfg->mainWincfg);
                        break;
                    }
                    case 't': {
                        wmove(wincfg->mainWincfg->mainWin, wincfg->mainWincfg->h, 0);
                        wclrtoeol(wincfg->mainWincfg->mainWin);
                        strcpy(wincfg->mainWincfg->fileName, "\0");
                        wincfg->mainWincfg->getInput = 1;
                        wincfg->mainWincfg->inputMode = 2;
                        break;
                    }
                    case 'd': {
                        delFile(wincfg->mainWincfg);
                        getFiles(wincfg->mainWincfg);
                        break;
                    }
                    case 'l': {
                        wmove(wincfg->mainWincfg->mainWin, 0, 0);
                        wclrtoeol(wincfg->mainWincfg->mainWin);
                        strcpy(wincfg->mainWincfg->currentDir, "\0");
                        wincfg->mainWincfg->getInput = 1;
                        wincfg->mainWincfg->inputMode = 1;
                        break;
                    }
                    default: break;
                }
                showFiles(wincfg->mainWincfg);
            }
            else {
                getInput(wincfg->mainWincfg, ch);
            }
        }
    }

    endwin();
    free(wincfg->mainWincfg->currentDir);
    free(wincfg->mainWincfg);
    free(wincfg->cmdWincfg);
    free(wincfg);
    return 0;
}
