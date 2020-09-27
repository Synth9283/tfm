#include <stdlib.h>
#include <stdint.h>
#include <ncurses.h>
#include "libs/wincfg.h"
#include "libs/winSetup.h"
#include "libs/getFiles.h"

int main(int argc, char **argv) {
    (void)argc; (void)argv;

    uint16_t ch;
    Wincfg_t *wincfg = winSetup();
    for (;;) {
        if ((ch = getch()) == ERR) {
            continue;
        }
        else if (ch == 'q') break;
        else {
            switch(ch) {
                case KEY_DOWN: break;
                case KEY_UP: break;
                default: break;
            }
            wrefresh(wincfg->mainWincfg->mainWin);
        }
    }

    endwin();
    free(wincfg->mainWincfg);
    free(wincfg->cmdWincfg);
    free(wincfg);
    // puts(getFiles("/")[0]);
    return 0;
}
