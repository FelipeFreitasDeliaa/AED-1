/*Felipe Freitas D' Elia
 RA: 176284*/

#include <stdio.h>
#include <stdlib.h>

void funcao_deslocar(char* palavra, int tamanho, int deslocamento) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < deslocamento; j++) {
            if (palavra[i] - 1 >= 'A') {
                palavra[i]--;
            } else {
                palavra[i] = 'Z';
            }
        }
    }
}

int main() {
    int casos_teste;
    int deslocamento;
    int tamanho;
    char* string = malloc(50 * sizeof(char));

    scanf("%d", &casos_teste);
    getchar();

    for (int i = 0; i < casos_teste; i++) {
        tamanho = 0;

        while (1) {
            char c;
            scanf("%c", &c);
            if (c == '\n') break;
            string[tamanho++] = c;
        }
        string[tamanho] = '\0';

        scanf("%d", &deslocamento);
        getchar();

        if (deslocamento == 0){
            for (int i = 0; i < tamanho; i++) {
                printf("%c", string[i]);
            }

        }
        else{
            funcao_deslocar(string, tamanho, deslocamento);

        for (int i = 0; i < tamanho; i++) {
            printf("%c", string[i]);
            }
        }
        printf("\n");

    }

    free(string);
    return 0;
}
