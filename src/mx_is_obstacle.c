#include "../inc/header.h"

bool mx_is_obstacle(char *path, int x, int y) {
    int _file = open(path, O_RDONLY);
    char temp[1];
    int count;
    int x_count = -1;
    int y_count = 0;
    while ((count = read(_file, temp, 1)) > 0) {
        char text[] = "0";
        text[0] = *temp;
        if (y_count == y) {
            x_count++;
        }
        if (x_count == x * 2) {
            close(_file);
            return text[0] == '#' ? 1 : 0;
        }
        if (text[0] == '\n') {       
            y_count++;
        }
    }
    return 0;
}

