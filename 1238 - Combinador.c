/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <string.h>

void combinar_strings(char string_1[], char string_2[], char resultado[]) {
    int i = 0, j = 0, k = 0;

    while (string_1[i] != '\0' && string_2[j] != '\0') {
        resultado[k++] = string_1[i++];
        resultado[k++] = string_2[j++];
    }

    while (string_1[i] != '\0') {
        resultado[k++] = string_1[i++];
    }

    while (string_2[j] != '\0') {
        resultado[k++] = string_2[j++];
    }

    resultado[k] = '\0';
}

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);
    getchar();

    while (casos_teste--) {
        char cadeia_de_caracteres[102];
        char string_1[51], string_2[51], resultado[101];

        fgets(cadeia_de_caracteres, sizeof(cadeia_de_caracteres), stdin);
        cadeia_de_caracteres[strcspn(cadeia_de_caracteres, "\n")] = '\0';

        char *parcela_1 = strtok(cadeia_de_caracteres, " ");
        char *parcela_2 = strtok(NULL, " ");

        strcpy(string_1, parcela_1);
        strcpy(string_2, parcela_2);

        combinar_strings(string_1, string_2, resultado);

        printf("%s\n", resultado);
    }

    return 0;
}
