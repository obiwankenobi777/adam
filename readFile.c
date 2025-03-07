/*
 * read file; count lines, chars, spaces;
 * count words;
 * 
 */
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Argumentos ausentes!\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");

    if (!f) {
        perror("Erro na leitura do arquivo!\n");
        return 1;
    }

    int lines = 0, chars = 0, words = 0;
    char ch;

    while ((ch = fgetc(f)) != EOF) {
        if (ch == ' ' || ch == '\n')
            ++words;
        if (ch == '\n') 
            ++lines;
        ++chars;
    }
    printf("Lines: %d\nChars: %d\nWords: %d\n", lines, chars, words);

    fclose(f);

    return 0;
}
