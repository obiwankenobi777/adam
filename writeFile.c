#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Parametro Ausente!\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "w");
    if (!f) {
        perror("Erro na abertura do arquivo!\n");
        return 1;
    }

    const char name[] = "francisco ian soares de araujo\n";
    if (fputs(name, f) != -1)
        printf("Escrita realizada com sucesso!\n");

    fclose(f);
    
    return 0;
}
