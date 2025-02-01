#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(char *v, int inicio, int fim) {
    if (inicio < fim) {
        char pivo = v[fim];
        int i = inicio;
        for (int j = inicio; j < fim; j++) {
            if (v[j] <= pivo) {
                char temp = v[i];
                v[i] = v[j];
                v[j] = temp;
                i++;
            }
        }
        v[fim] = v[i];
        v[i] = pivo;
        quicksort(v, inicio, i - 1);
        quicksort(v, i + 1, fim);
    }
}

void comparar_strings(char dieta[], char manha[], char almoco[]) {
    int count[26] = {0};
    int cheater = 0;

    for (int i = 0; dieta[i] != '\0'; i++) {
        count[dieta[i] - 'A']++;
    }

    for (int i = 0; manha[i] != '\0'; i++) {
        if (count[manha[i] - 'A'] == 0) {
            cheater = 1;
            break;
        }
        count[manha[i] - 'A']--;
    }

    for (int i = 0; almoco[i] != '\0'; i++) {
        if (count[almoco[i] - 'A'] == 0) {
            cheater = 1;
            break;
        }
        count[almoco[i] - 'A']--;
    }

    if (cheater) {
        printf("CHEATER\n");
    } else {
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                printf("%c", 'A' + i);
            }
        }
        printf("\n");
    }
}

int main() {
    int testes;
    scanf("%d", &testes);
    getchar();

    for (int i = 0; i < testes; i++) {
        char dieta[27] = {0};
        char manha[27] = {0};
        char almoco[27] = {0};
        char c;
        int tamanho_dieta = 0, tamanho_manha = 0, tamanho_almoco = 0;

        while (1) {
            c = getchar();
            if (c == '\n' || c == EOF) break;
            dieta[tamanho_dieta++] = c;
        }
        dieta[tamanho_dieta] = '\0';

        while (1) {
            c = getchar();
            if (c == '\n' || c == EOF) break;
            manha[tamanho_manha++] = c;
        }
        manha[tamanho_manha] = '\0';

        while (1) {
            c = getchar();
            if (c == '\n' || c == EOF) break;
            almoco[tamanho_almoco++] = c;
        }
        almoco[tamanho_almoco] = '\0';

        quicksort(dieta, 0, tamanho_dieta - 1);
        quicksort(manha, 0, tamanho_manha - 1);
        quicksort(almoco, 0, tamanho_almoco - 1);

        comparar_strings(dieta, manha, almoco);
    }

    return 0;
}
