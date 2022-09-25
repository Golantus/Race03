#include "../inc/header.h"

bool mx_map_exist(char *path) {
    int _file = open(path, O_RDONLY);
    char temp[1];
    if (_file < 0 || read(_file, temp, 1) == 0) {
        close(_file);
        return 0;
    }
    close(_file);
    return 1;
}

