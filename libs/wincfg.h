#pragma once
#include <stdint.h>
#include <ncurses.h>

typedef struct {
    uint16_t y, x, w, h, fileCount, selected;
    char *currentDir;
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
