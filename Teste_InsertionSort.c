//Felipe Freitas D' Elia
//RA: 176284

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 20000; //constante para tamanho do vetor

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
    clock_t t; // Variável para armazenar tempo
    int vetor[TAM];

    // Semente de aleatoriedade
    srand((unsigned)time(NULL));

    // Geração aleatória dos valores do vetor
    for (int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    // Verificando tempo de execução do InsertionSort
    printf("Ordenando vetor de tamanho %d...\n", TAM);
    t = clock(); // Armazena tempo
    insertionsort(TAM, vetor);
    t = clock() - t; // Tempo final - inicial

    // Imprime o tempo na tela
    printf("Tempo de execucao: %lf s\n", ((double)t) / ((CLOCKS_PER_SEC))); // Conversão para double

    return 0;
}
