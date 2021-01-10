#ifdef unix
#include <unistd.h>
#define GetCurrentDir _getcwd
#elif WIN32
#include <direct.h>
#define GetCurrentDir getcwd
#endif
#include <stdlib.h>

char *getCwd() {
    char *cwd = malloc(255);
    GetCurrentDir(cwd, 255);
    return cwd;
}
