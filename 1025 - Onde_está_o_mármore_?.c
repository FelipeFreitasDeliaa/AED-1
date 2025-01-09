/*Felipe Freitas D' Elia 
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int *v, int n, int x) {
    int inicio = 0, fim = n - 1, meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (v[meio] == x) {
            
            while (meio > 0 && v[meio - 1] == x) {
                meio--;
            }
            return meio + 1;
        } else if (v[meio] < x) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int particiona(int *v, int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;
    return i + 1;
}

void quicksort(int *v, int inicio, int fim) {
    if (inicio < fim) {
        int pos = particiona(v, inicio, fim);
        quicksort(v, inicio, pos - 1);
        quicksort(v, pos + 1, fim);
    }
}

int main() {
    int casos_teste = 1;
    int numero_de_marmores, numero_de_consultas;

    while (1) {
        scanf("%d %d", &numero_de_marmores, &numero_de_consultas);

        if (numero_de_marmores == 0 && numero_de_consultas == 0) {
            break;
        }

        int *vetor_de_numeros = malloc(numero_de_marmores * sizeof(int));
        int *vetor_consulta = malloc(numero_de_consultas * sizeof(int));

        for (int i = 0; i < numero_de_marmores; i++) {
            scanf("%d", &vetor_de_numeros[i]);
        }

        quicksort(vetor_de_numeros, 0, numero_de_marmores - 1);

        for (int i = 0; i < numero_de_consultas; i++) {
            scanf("%d", &vetor_consulta[i]);
        }

        printf("CASE# %d:\n", casos_teste);
        for (int i = 0; i < numero_de_consultas; i++) {
            int posicao = busca_binaria(vetor_de_numeros, numero_de_marmores, vetor_consulta[i]);
            if (posicao == -1) {
                printf("%d not found\n", vetor_consulta[i]);
            } else {
                printf("%d found at %d\n", vetor_consulta[i], posicao);
            }
        }

        free(vetor_de_numeros);
        free(vetor_consulta);
        casos_teste++;
    }

    return 0;
}
