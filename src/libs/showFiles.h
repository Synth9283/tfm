#pragma once
#ifdef unix
#include <ncurses.h>
#elif _WIN32
#include <ncursesw/curses.h>
#endif
#include "wincfg.h"

void showFiles(MainWincfg_t *win);
