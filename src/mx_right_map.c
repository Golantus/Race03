#include "../inc/header.h"

bool mx_right_map(char *path) {
    int _file = open(path, O_RDONLY);
    char temp[1];
    int count;
    int x_count = 0;
    int first_x = 0;
    while ((count = read(_file, temp, 1)) > 0) {
        char text[] = "0";
        text[0] = *temp;
        if (text[0] != '#' && text[0] != '.' && text[0] != ',' && text[0] != '\n') {
            close(_file);
            return 0;
        }
        x_count++;
        if (text[0] == '\n') {
            if (first_x == 0) {
                first_x = x_count;
            }
            else if (x_count != first_x) {
                close(_file);
                return 0;
            }
            x_count = 0;
        }
    }
    close(_file);
    return 1;
}

