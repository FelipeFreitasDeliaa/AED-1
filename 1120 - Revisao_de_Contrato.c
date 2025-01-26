/*Felipe Freitas D' Elia
 RA: 176284*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int saida(char defeito, char* numero, char* nova) {
    int tamanho_nova = 0;

    for (int i = 0; numero[i] != '\0'; i++) {
        if (numero[i] != defeito) {
            nova[tamanho_nova++] = numero[i];
        }
    }
    nova[tamanho_nova] = '\0'; 
    return tamanho_nova;
}

int main() {
    char defeito;
    char* numero = malloc(101 * sizeof(char));
    char* nova_string = malloc(101 * sizeof(char));

    while (1) {
        scanf(" %c %s", &defeito, numero);

        if (defeito == '0' && strcmp(numero, "0") == 0) {
            break;
        }

        int tamanho_nova = saida(defeito, numero, nova_string);

        if (tamanho_nova == 0) {
            printf("0\n");
        } else {
            int inicio = 0;
            while (nova_string[inicio] == '0' && inicio < tamanho_nova) {
                inicio++;
            }

            if (nova_string[inicio] == '\0') {
                printf("0\n");
            } else {
                printf("%s\n", &nova_string[inicio]);
            }
        }
    }

    free(numero);
    free(nova_string);
    return 0;
}
