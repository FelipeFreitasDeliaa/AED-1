/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>

int comparar_crescente(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int comparar_decrescente(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int numero_de_linhas;
    int numero;

    do {
        scanf("%d", &numero_de_linhas);
    } while (numero_de_linhas <= 1 || numero_de_linhas > 100000);

    int* pares = (int*)malloc(numero_de_linhas * sizeof(int));
    int* impares = (int*)malloc(numero_de_linhas * sizeof(int));

    int qtd_pares = 0, qtd_impares = 0;

    for (int i = 0; i < numero_de_linhas; i++) {
        scanf("%d", &numero);

        if (numero % 2 == 0) {
            pares[qtd_pares++] = numero;
        } else {
            impares[qtd_impares++] = numero;
        }
    }

    qsort(pares, qtd_pares, sizeof(int), comparar_crescente);
    qsort(impares, qtd_impares, sizeof(int), comparar_decrescente);

    for (int i = 0; i < qtd_pares; i++) {
        printf("%d\n", pares[i]);
    }
    for (int i = 0; i < qtd_impares; i++) {
        printf("%d\n", impares[i]);
    }

    free(pares);
    free(impares);

    return 0;
}
