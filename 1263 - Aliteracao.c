/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>

void aliteracoes(char linha[], int tamanho) {
    int num_aliteracoes = 0;
    char anterior = '\0';
    char atual;
    int em_sequencia = 0;

    for (int i = 0; i < tamanho; i++) {

        if (linha[i] == ' ') continue;

        atual = (linha[i] >= 'A' && linha[i] <= 'Z') ? linha[i] + 32 : linha[i];

        if (atual == anterior) {
            if (!em_sequencia) { 
                num_aliteracoes++;
                em_sequencia = 1;
            }
        } else {
            em_sequencia = 0;
        }

        anterior = atual;

        while (i < tamanho && linha[i] != ' ') i++; 
    }

    printf("%d\n", num_aliteracoes);
}

int main() {
    char linha[5052];
    int tamanho;
    char c;

    while (1) {
        tamanho = 0;

        while ((c = getchar()) != EOF && c != '\n') {
            linha[tamanho++] = c;
        }

        if (tamanho == 0 && c == EOF) break;

        linha[tamanho] = '\0';

        aliteracoes(linha, tamanho);
    }

    return 0;
}
