#include <stdlib.h>
#ifdef unix
#include <unistd.h>
#define GetCurrentDir getcwd
#elif WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#endif

char *getCwd() {
    char *cwd = malloc(255);
    GetCurrentDir(cwd, 255);
    return cwd;
}
