#include "../inc/header.h"

int **matrix (char *res, int *rows, int *cols) 
{
    int i;
    int r = 0;
    int c = 0;

    for (i = 0; res[i] != '\0'; ++i)
        if (res[i] == '\n')
           ++c;
    
    r = (i - c) / c;

    int **mat = (int **)malloc(c * 8);

    for (int i = 0; i < c; i++)
        mat[i] = (int*)malloc(r * 4);
    
    for (int i = 0; i < c; ++i) 
    {
        for (int j = 0; j < r; ++j) 
        {
            if (i == 0) 
            {
                if (res[j] == '#') mat[i][j] = -1;
                else if (res[j] == '.') mat[i][j] = -2;
                else if (res[j] != ',' && res[j] != '\n') 
                {
                    mx_printerr("map error\n");
                    exit(0);
                }
            }
            else 
            {
                if (res[j + i * (r + 1)] == '#') mat[i][j] = -1;
                else if (res[j + i * (r + 1)] == '.') mat[i][j] = -2;
                else if (res[j + i * (r + 1)] != ',' && res[j + i * (r + 1)] != '\n') 
                {
                    mx_printerr("map error\n");
                    exit(0);
                }
            }
        }
    }
    
    *cols = r;
    *rows = c;
    return mat;
}

