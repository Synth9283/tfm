#include <dirent.h>
#include "../libs/wincfg.h"

void delFile(MainWincfg_t *win) {
    if (!win->files[win->selected]) return;
    DIR *dir = opendir(win->files[win->selected]);
    
    if (!dir) {
        remove(win->files[win->selected]);
    }

    closedir(dir);
}
