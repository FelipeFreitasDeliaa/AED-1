#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 20000; //constante para tamanho do vetor

int separa(int inicio, int fim, int v[]) {
    int c, j, k, t;
    c = v[fim];
    j = inicio;
    for (k = inicio; k < fim; k++) {
        if (v[k] <= c) {
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
    }
    v[fim] = v[j];
    v[j] = c;
    return j;
}

void quicksort(int inicio, int fim, int v[]) {
    int j;
    if (inicio < fim) {
        j = separa(inicio, fim, v); 
        quicksort(inicio, j - 1, v); 
        quicksort(j + 1, fim, v);    
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

    // Verificando tempo de execução do quicksort
    printf("Ordenando vetor de tamanho %d...\n", TAM);
    t = clock(); // Armazena tempo
    quicksort(0, TAM - 1, vetor);
    t = clock() - t; // Tempo final - inicial

    // Imprime o tempo na tela
    printf("Tempo de execucao: %lf s\n", ((double)t) / ((CLOCKS_PER_SEC))); // Conversão para double

    return 0;
}
