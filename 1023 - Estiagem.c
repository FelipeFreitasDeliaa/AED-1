/*Felipe Freitas D' Elia
  RA: 176284*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct no {
    int pessoas;
    int consumo_medio;
    struct no* prox;
} NO;

NO* inserir_em_ordem(NO** Lista, int moradores, int consumo) {
    NO* atual = *Lista;

    while (atual != NULL) {
        if (atual->consumo_medio == consumo) {
            atual->pessoas += moradores;
            return *Lista;
        }
        atual = atual->prox;
    }

    NO* novo_no = (NO*)malloc(sizeof(NO));
    novo_no->pessoas = moradores;
    novo_no->consumo_medio = consumo;
    novo_no->prox = NULL;

    if (*Lista == NULL || (*Lista)->consumo_medio > consumo) {
        novo_no->prox = *Lista;
        *Lista = novo_no;
    } else {
        NO* anterior = NULL;
        atual = *Lista;

        while (atual != NULL && atual->consumo_medio <= consumo) {
            anterior = atual;
            atual = atual->prox;
        }

        novo_no->prox = atual;
        anterior->prox = novo_no;
    }

    return *Lista;
}

void imprimir_lista(NO** Lista) {
    NO* aux = *Lista;
    int primeiro = 1;

    while (aux != NULL) {
        if (primeiro) {
            printf("%d-%d", aux->pessoas, aux->consumo_medio);
            primeiro = 0;
        } else {
            printf(" %d-%d", aux->pessoas, aux->consumo_medio);
        }
        aux = aux->prox;
    }
}

void liberar_lista(NO** Lista) {
    NO* aux = *Lista;
    while (aux != NULL) {
        NO* temp = aux;
        aux = aux->prox;
        free(temp);
    }
    *Lista = NULL;
}

int main() {
    int qtd_imoveis, qtd_moradores, casos_teste = 1;
    long long int consumo_total;

    while (1) {

        if (casos_teste > 1) {
            printf("\n");
        }

        scanf("%d", &qtd_imoveis);
        if (qtd_imoveis == 0) break;

        NO* Lista = NULL;
        long long int soma_consumo = 0, soma_qtd_moradores = 0;

        for (int i = 0; i < qtd_imoveis; i++) {
            scanf("%d %lld", &qtd_moradores, &consumo_total);
            int consumo_medio = consumo_total / qtd_moradores;

            Lista = inserir_em_ordem(&Lista, qtd_moradores, consumo_medio);
            soma_consumo += consumo_total;
            soma_qtd_moradores += qtd_moradores;
        }

        double consumo_medio_total = soma_consumo / (float)soma_qtd_moradores;

        printf("Cidade# %d:\n", casos_teste);
        imprimir_lista(&Lista);
        printf("\nConsumo medio: %.2f m3.\n", floor(consumo_medio_total * 100) / 100);

        liberar_lista(&Lista);
        casos_teste++;
    }

    return 0;
}
