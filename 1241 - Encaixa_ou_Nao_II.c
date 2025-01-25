/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <string.h>

int comparar_strings(char* numero_1, char* numero_2, int tamanho_1, int tamanho_2) {
    if (tamanho_2 > tamanho_1) {
        return 0;
    }
    for (int i = 0; i < tamanho_2; i++) {
        if (numero_1[tamanho_1 - tamanho_2 + i] != numero_2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);

    char string_1[1001], string_2[1001];

    for (int i = 0; i < casos_teste; i++) {
        scanf("%s %s", string_1, string_2);

        int tamanho_1 = strlen(string_1);
        int tamanho_2 = strlen(string_2);

        if (comparar_strings(string_1, string_2, tamanho_1, tamanho_2)) {
            printf("encaixa\n");
        } else {
            printf("nao encaixa\n");
        }
    }

    return 0;
}
