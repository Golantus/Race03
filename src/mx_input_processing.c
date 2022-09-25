#include "../inc/header.h"

void mx_input_processing(int argc, char *argv[]) {
    if (argc != 6) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        exit(-1);
    }
    if (!mx_map_exist(argv[1])) {
        mx_printerr("map does not exist\n");
        exit(-1);
    }
    if (!mx_right_map(argv[1])) {
        mx_printerr("map error\n");
        exit(-1);
    }
    int x1 = atoi(argv[2]);
    int y1 = atoi(argv[3]);
    int x2 = atoi(argv[4]);
    int y2 = atoi(argv[5]);
    if (mx_points_outof_range(argv[1], x1, y1, x2, y2)) {
        mx_printerr("points are out of map range\n");
        exit(-1);
    }
    if (mx_is_obstacle(argv[1], x1, y1)) {
        mx_printerr("entry point cannot be an obstacle\n");
        exit(-1);
    }
    if (mx_is_obstacle(argv[1], x2, y2)) {
        mx_printerr("exit point cannot be an obstacle\n");
        exit(-1);
    }
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) {
        mx_printerr("error\n");
    }
}

