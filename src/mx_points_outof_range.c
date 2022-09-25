#include "../inc/header.h"

bool mx_points_outof_range(char *path, int x1, int y1, int x2, int y2) {
    int _file = open(path, O_RDONLY);
    char temp[1];
    int count;
    int x_count = -1;
    int y_count = -1;
    bool first_line = 1;
    while ((count = read(_file, temp, 1)) > 0) {
        char text[] = "0";
        text[0] = *temp;
        if (text[0] == '\n') {
            if (first_line) {
                first_line = 0;
            }
            y_count++;
        }
        if (first_line) {
            x_count++;
        }
    }
    close(_file);
    if (y1 > y_count || y2 > y_count || x1 * 2 > x_count || x2 * 2 > x_count) {
        return 1;
    }
    return 0;
}

