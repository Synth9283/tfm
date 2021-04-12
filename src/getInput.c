#include <string.h>
#include "libs/wincfg.h"
#include "libs/getInput.h"
#include "libs/showFiles.h"
#include "libs/getFiles.h"
#include "libs/createFile.h"
#ifdef unix
#include <ncurses.h>
#elif WIN32
#include <ncursesw/curses.h>
#endif

// inputMode 1 = directory, 2 = fileName
void getInput(MainWincfg_t *win, uint16_t ch) {
    if (win->inputMode == 1) {
        if (ch == '\n') {
            getFiles(win);
            showFiles(win);
            win->curseY = 0;
            win->curseX = 0;
            win->getInput = 0;
            win->inputMode = 0;
        }
        else {
            for (uint16_t i=0; i<win->w; i++) {
                if (win->currentDir[i] == '\0') {
                    switch(ch) {
                        case KEY_BACKSPACE:
                        case 127:
                        case 8: {
                            if (i != 0) {
                                win->currentDir[i-1] = '\0';
                                mvwdelch(win->mainWin, 0, i-1);
                                if (win->curseX > 0) win->curseX--;
                            }
                            break;
                        }
                        default: {
                            win->currentDir[i] = ch;
                            mvwaddch(win->mainWin, 0, i, ch);
                            win->currentDir[i+1] = '\0';
                            win->curseX++;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        getFiles(win);
        showFiles(win);
        wrefresh(win->mainWin);
    }
    else if (win->inputMode == 2) {
        if (ch == '\n') {
            win->curseY = 0;
            win->curseX = 0;
            win->selected = 0;
            win->offset = 0;
            win->getInput = 0;
            win->inputMode = 0;
            createFile(win);
            strcpy(win->fileName, "");
            getFiles(win);
            showFiles(win);
        }
        else {
            for (uint16_t i=0; i<win->w; i++) {
                if (win->fileName[i] == '\0') {
                    switch(ch) {
                        case KEY_BACKSPACE:
                        case 127:
                        case 8: {
                            if (i != 0) {
                                win->fileName[i-1] = '\0';
                                mvwdelch(win->mainWin, win->curseY, i-1);
                                if (win->curseX > 0) win->curseX--;
                            }
                            break;
                        }
                        default: {
                            win->fileName[i] = ch;
                            mvwaddch(win->mainWin, win->curseY, i, ch);
                            win->fileName[i+1] = '\0';
                            win->curseX++;
                            break;
                        }
                    }
                    break;
                }
            }
            wrefresh(win->mainWin);
        }
    }
}
