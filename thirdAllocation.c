/*
 * third method of memory allocation  by backes
 * */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *v;
    int **p;
    int i, j, lines = 2, columns = 2;
    v = (int*)malloc(lines * columns * sizeof(int));
    p = (int**)malloc(lines * sizeof(int*));

    for (i = 0; i < lines; ++i) {
        p[i] = v + i * columns;
        for (j = 0; j < columns; ++j)
            p[i][j] = i + j + 1;
    }

    for (i = 0; i < lines; ++i) {
        for (j = 0; j < columns; ++j) {
            printf("%d ", p[i][j]);
        }
        putc('\n', stdout);
    }
    free(v);
    free(p);

    return 0;
}
