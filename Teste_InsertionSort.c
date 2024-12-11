//Felipe Freitas D' Elia
//RA: 176284

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

void insertionsort(int tamanho, int v[]) {
    int i, j, x;
    for (j = 1; j < tamanho; j++) {
        x = v[j];
        for (i = j - 1; i >= 0 && v[i] > x; i--) {
            v[i + 1] = v[i];
        }
        v[i + 1] = x;
    }
}

int main() {
    const int incremento = 20000;
    const int maximo = 400000;
    int tamanho_atual = 20000;

    clock_t t;

    while (tamanho_atual <= maximo) {
        // Aloca dinamicamente o vetor com o tamanho atual
        int *vetor = (int *)malloc(tamanho_atual * sizeof(int));
        if (vetor == NULL) {
            printf("Erro ao alocar memoria\n");
            return 1;
        }

        // Preenche o vetor com valores aleatórios
        srand((unsigned)time(NULL));
        for (int i = 0; i < tamanho_atual; i++) {
            vetor[i] = rand() % tamanho_atual;
        }

        // Mede o tempo de execução do insertion sort
        t = clock();
        insertionsort(tamanho_atual, vetor);
        t = clock() - t;

        // Imprime o tamanho do vetor e o tempo de execução
        printf("Tamanho do vetor: %d -> Tempo de execucao: %lf s\n",
               tamanho_atual, ((double)t) / CLOCKS_PER_SEC);

        // Libera a memória alocada
        free(vetor);

        // Incrementa o tamanho do vetor
        tamanho_atual += incremento;
    }

    return 0;
}
