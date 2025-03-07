#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Missing arguments!\n");
        return 1;
    }
    
    //open file for reading
    FILE *f = fopen(argv[1], "r");
    if (!f) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    
    //counting chars, lines, columns
    int chars = 0, lines = 0, current_columns = 0, max_columns = 0;
    char c;
    while ((c = fgetc(f)) != EOF) {
        ++chars;
        ++current_columns;
        if (c == '\n') {
            ++lines;
            if (current_columns > max_columns) {
                max_columns = current_columns;
            }
            current_columns = 0;
        }
    }

    //returning to the beginning to the file
    rewind(f);

    //memory allocation
    char **buffer = (char**)malloc(lines * sizeof(char*));
    if (!buffer) {
        printf("Memory allocation ERROR!\n");
        fclose(f);
        return 1;
    }
    for (int i = 0; i < lines; ++i) {
        buffer[i] = (char*)malloc(max_columns * sizeof(char));

        if (!buffer[i]) {
            printf("Memory allocation ERROR!\n");
            for (int j = 0; j < i; ++j) {
                free(buffer[j]);
            }
            free(buffer);
            buffer = NULL;
            fclose(f);
            return 1;
        }
    }

    //tranfering file contents to buffer
    int row = 0, col = 0;
    while ((c = fgetc(f)) != EOF) {
        buffer[row][col++] = c;
        if (c == '\n') {
            buffer[row++][col] = '\0';
            col = 0;
        }
    }

    //show me the buffer
    for (int i = 0; i < lines; ++i) {
        printf("%d  ", i + 1);
        for (int j = 0; buffer[i][j] != '\0'; ++j) {
            printf("%c", buffer[i][j]);
        }
    }
    printf("Lines: %d\nChars: %d\n", lines, chars);

    //closing file and freeing memory
    fclose(f);

    for (int i = 0; i < lines; ++i) 
        free(buffer[i]);
    free(buffer);
    buffer = NULL;

    return 0;
}
