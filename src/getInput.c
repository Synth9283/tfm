#include <string.h>
#include "../libs/wincfg.h"
#include "../libs/getInput.h"
#include "../libs/showFiles.h"
#include "../libs/getFiles.h"
#include "../libs/createFile.h"
#ifdef unix
#include <ncurses.h>
#elif WIN32
#include <ncursesw/curses.h>
#endif

// inputMode 1 = directory, 2 = fileName
void getInput(MainWincfg_t *win, uint16_t ch) {
    if (ch == '\n') {
        getFiles(win);
        showFiles(win);
        win->getInput = 0;
        win->inputMode = 0;
    }
    else {
        if (win->inputMode = 1) {
            for (uint16_t i=0; i<win->w; i++) {
                if (win->currentDir[i] == '\0') {
                    switch(ch) {
                        case KEY_BACKSPACE:
                        case 127:
                        case 8: {
                            if (i != 0) {
                                win->currentDir[i-1] = '\0';
                                mvwdelch(win->mainWin, 0, i-1);
                            }
                            break;
                        }
                        default: {
                            win->currentDir[i] = ch;
                            mvwaddch(win->mainWin, 0, i, ch);
                            win->currentDir[i+1] = '\0';
                            break;
                        }
                    }
                    break;
                }
            }
        }
        // else if (win->inputMode = 2) {
        //     createFile(win);
        // }   
    }
}
