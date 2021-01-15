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
            if (!wincfg->mainWincfg->dirInput) {
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
                    case 'l': {
                        wmove(wincfg->mainWincfg->mainWin, 0, 0);
                        wclrtoeol(wincfg->mainWincfg->mainWin);
                        strcpy(wincfg->mainWincfg->currentDir, "\0");
                        wincfg->mainWincfg->dirInput = 1;
                        break;
                    }
                    default: break;
                }
                showFiles(wincfg->mainWincfg);
            }
            else {
                if (ch == '\n') {
                    getFiles(wincfg->mainWincfg);
                    showFiles(wincfg->mainWincfg);
                    wincfg->mainWincfg->dirInput = 0;
                }
                else {
                    for (uint16_t i=0; i<wincfg->mainWincfg->w; i++) {
                        if (wincfg->mainWincfg->currentDir[i] == '\0') {
                            switch(ch) {
                                case KEY_BACKSPACE:
                                case 127:
                                case 8: {
                                    if (i != 0) {
                                        wincfg->mainWincfg->currentDir[i-1] = '\0';
                                        mvwdelch(wincfg->mainWincfg->mainWin, 0, i-1);
                                    }
                                    break;
                                }
                                default: {
                                    wincfg->mainWincfg->currentDir[i] = ch;
                                    mvwaddch(wincfg->mainWincfg->mainWin, 0, i, ch);
                                    wincfg->mainWincfg->currentDir[i+1] = '\0';
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }
                wrefresh(wincfg->mainWincfg->mainWin);
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
