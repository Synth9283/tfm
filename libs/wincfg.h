#pragma once
#include <stdint.h>
#ifdef unix
#include <ncurses.h>
#elif _WIN32
#include <ncursesw/curses.h>
#endif

typedef struct {
    uint8_t getInput, inputMode;
    uint16_t y, x, w, h, fileCount, offset, selected;
    char *currentDir, *fileName, *status, **files;
    WINDOW *mainWin;
} MainWincfg_t;

typedef struct {
    uint16_t y, x, w, h;
    WINDOW *cmdWin;
} CmdWincfg_t;

typedef struct {
    uint16_t w, h;
    MainWincfg_t *mainWincfg;
    CmdWincfg_t *cmdWincfg;
} Wincfg_t;
