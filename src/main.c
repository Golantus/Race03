    #include "../inc/header.h"

int main(int argc, char *argv[]) {

    mx_input_processing(argc, argv);
    int src = open(argv[1], O_RDONLY);
    char s[1];
    read (src, s, 4);
    int rows, cols, len;
    int x1 = mx_atoi(argv[2]), x2 = mx_atoi(argv[4]);
    int y1 = mx_atoi(argv[3]), y2 = mx_atoi(argv[5]);

    char *str = mx_file_to_str(argv[1]);
    int **mat = matrix(str, &rows, &cols);  
    char **final = cmatrix(str, &rows, &cols);
    int **mat1 = matrix(str, &rows, &cols);

    int px[rows * cols], py[rows * cols];

    if (!path(mat,x1,y1,x2,y2,rows,cols,&len,px,py)) {
        mx_printerr("route not found\n");
        exit(0);
    }
    path(mat,x1,y1,x2,y2,rows,cols,&len,px,py);

    int file1 = open("path.txt",O_WRONLY);
    if (file1 < 0)
        file1 = open("path.txt", O_CREAT | O_WRONLY);

    for (int i = 0; i < len ; ++i)
            final[py[i]][px[i]] = '*';

    final[y2][x2] = '*';
    max(mat1, x1, y1, rows, cols, final);

    for (int i = 0; i < rows ; ++i) {
        for (int j = 0; j < cols ; ++j) {
            char s = final[i][j];
            write(file1, &s, 1);
        }
        write(file1, "\n", 1);
    }

    close(file1);
        
    mx_printstr("dist=");
    mx_printint(max(mat1,x1,y1,rows,cols,final));
    mx_printstr("\n");
    mx_printstr("exit=");
    mx_printint(len);
    mx_printstr("\n");
    
    return 0;
}

