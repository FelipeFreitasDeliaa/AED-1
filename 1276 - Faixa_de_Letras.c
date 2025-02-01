/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <ctype.h>

void quicksort(int inicio, int fim, char v[]) {
    if (inicio < fim) {
        int pivo = v[fim], i = inicio, j;
        for (j = inicio; j < fim; j++) {
            if (v[j] < pivo) {
                char temp = v[i];
                v[i] = v[j];
                v[j] = temp;
                i++;
            }
        }
        v[fim] = v[i];
        v[i] = pivo;

        quicksort(inicio, i - 1, v);
        quicksort(i + 1, fim, v);
    }
}

int main() {
    char linha[51], unicos[51];
    int tamanho = 0, novo_tamanho = 0;
    char c;

    while (1) {
        c = getchar();
        if (c == EOF) break;
        if (c != ' ' && islower(c)) {
            linha[tamanho++] = c;
        }
        if (c == '\n') {
            if (tamanho == 0) {
                printf("\n");
                continue;
            }

            quicksort(0, tamanho - 1, linha);

            novo_tamanho = 0;
            for (int i = 0; i < tamanho; i++) {
                if (i == 0 || linha[i] != linha[i - 1]) {
                    unicos[novo_tamanho++] = linha[i];
                }
            }

            int i = 0;
            while (i < novo_tamanho) {
                char inicio = unicos[i];

                while (i + 1 < novo_tamanho && unicos[i + 1] == unicos[i] + 1) {
                    i++;
                }

                printf("%c:%c", inicio, unicos[i]);

                if (i + 1 < novo_tamanho) {
                    printf(", ");
                }
                i++;
            }

            printf("\n");

            tamanho = 0;
        }
    }

    return 0;
}
