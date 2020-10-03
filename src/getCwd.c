#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include <stdlib.h>

char *getCwd() {
    char *cwd = malloc(255);
    GetCurrentDir(cwd, 255);
    return cwd;
}
