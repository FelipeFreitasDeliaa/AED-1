/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct itens {
    char fruta[51];
    float valor;
};

int particiona(struct itens *v, int inicio, int fim) {
    struct itens pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (strcmp(v[j].fruta, pivo.fruta) <= 0) {
            i++;
            struct itens temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    struct itens temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;
    return i + 1;
}

void quicksort(struct itens *v, int inicio, int fim) {
    if (inicio < fim) {
        int pos = particiona(v, inicio, fim);
        quicksort(v, inicio, pos - 1);
        quicksort(v, pos + 1, fim);
    }
}

int busca_binaria(struct itens *v, int tamanho, char *fruta_desejada) {
    int inicio = 0, fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(fruta_desejada, v[meio].fruta);

        if (cmp == 0) {
            return meio;  
        } else if (cmp < 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return -1;
}

int main() {
    int qtd_idas, disponiveis, desejados;

    scanf("%d", &qtd_idas);

    for (int i = 0; i < qtd_idas; i++) {
        scanf("%d", &disponiveis);

        struct itens *vetor_disponiveis = (struct itens *) malloc(disponiveis * sizeof(struct itens));

        for (int j = 0; j < disponiveis; j++) {
            scanf("%s", vetor_disponiveis[j].fruta);
            scanf("%f", &vetor_disponiveis[j].valor);
        }

        quicksort(vetor_disponiveis, 0, disponiveis - 1);  // Ordenação do vetor disponível

        scanf("%d", &desejados);

        float custo_total = 0;

        for (int j = 0; j < desejados; j++) {
            char fruta_desejada[51];
            int quantidade;

            scanf("%s %d", fruta_desejada, &quantidade);

            int posicao = busca_binaria(vetor_disponiveis, disponiveis, fruta_desejada);

            if (posicao != -1) {
                custo_total += quantidade * vetor_disponiveis[posicao].valor;
            }
        }

        printf("R$ %.2f\n", custo_total);

        free(vetor_disponiveis);
    }

    return 0;
}
