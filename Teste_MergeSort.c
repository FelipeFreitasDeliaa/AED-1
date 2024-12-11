#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 20000; //constante para tamanho do vetor

void intercala(int inicio, int meio, int fim, int v[]) {
    int i, j, k, *w;
    w = malloc((fim - inicio) * sizeof(int));
    i = inicio;
    j = meio;
    k = 0;

    while (i < meio && j < fim) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            w[k++] = v[j++];
        }
    }

    while (i < meio) {
        w[k++] = v[i++];
    }

    while (j < fim) {
        w[k++] = v[j++];
    }

    for (i = inicio; i < fim; i++) {
        v[i] = w[i - inicio];
    }

    free(w);
}

void mergesort(int inicio, int fim, int v[]) {
    if (inicio < fim - 1) {
        int meio = (inicio + fim) / 2;
        mergesort(inicio, meio, v);
        mergesort(meio, fim, v);
        intercala(inicio, meio, fim, v);
    }
}

int main(){
    clock_t t; //variável para armazenar tempo
    int vetor[TAM];

    //semente de aleatoriedade
    srand((unsigned)time(NULL));

    //geração aleatório dos valores do vetor
    for(int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    //Verificando tempo de execução do merge sort
    t = clock(); //armazena tempo
    mergesort(0, TAM, vetor);
    t = clock() - t; //tempo final - tempo

    //imprime o tempo na tela
    printf("Tempo de execucao: %lf s\n", ((double)t)/((CLOCKS_PER_SEC))); //conversão para double

    return 0;
}
