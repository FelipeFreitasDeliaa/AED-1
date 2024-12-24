/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int num;
    struct no* prox;
} NO;

// Função para inserir um elemento no fim da lista, usando ponteiro para o final
NO* inserir_no_fim(NO** lista, NO** fim, int valor) {
    NO* novo_no = (NO*)malloc(sizeof(NO));
    novo_no->num = valor;
    novo_no->prox = NULL;

    if (*lista == NULL) { // Lista vazia
        *lista = novo_no;
        *fim = novo_no;
    } else { // Lista não vazia
        (*fim)->prox = novo_no;
        *fim = novo_no;
    }

    return *lista;
}

// Função para buscar e remover um elemento da lista
NO* busca_e_remocao(NO** lista, int valor) {
    NO* remover = *lista;
    NO* aux = NULL;

    while (remover != NULL && remover->num != valor) {
        aux = remover;
        remover = remover->prox;
    }

    if (remover != NULL) {
        if (aux == NULL) { // Remoção do primeiro nó
            *lista = remover->prox;
        } else { // Remoção de um nó intermediário ou final
            aux->prox = remover->prox;
        }
        free(remover);
    }

    return *lista;
}

// Função para imprimir a lista
void imprimir_lista(NO** lista) {
    NO* aux = *lista;

    while (aux != NULL) {
        if (aux->prox != NULL) {
            printf("%d ", aux->num);
        } else {
            printf("%d", aux->num);
        }
        aux = aux->prox; 
    }
}

int main() {
    NO* lista = NULL;
    NO* fim = NULL; // Ponteiro para o fim da lista

    int quantidade_inicial, pessoas_fora;

    // Entrada da quantidade inicial de pessoas
    do {
        scanf("%d", &quantidade_inicial);
    } while (quantidade_inicial < 1 || quantidade_inicial > 50000);

    int* identificador = malloc(quantidade_inicial * sizeof(int));

    // Inserir os elementos na lista
    for (int i = 0; i < quantidade_inicial; i++) {
        scanf("%d", &identificador[i]);
        inserir_no_fim(&lista, &fim, identificador[i]);
    }

    // Entrada da quantidade de pessoas fora
    do {
        scanf("%d", &pessoas_fora);
    } while (pessoas_fora < 1 || pessoas_fora >= quantidade_inicial);

    int* identificador_2 = malloc(pessoas_fora * sizeof(int));
    if (identificador_2 == NULL) {
        printf("Erro ao alocar memória.\n");
        free(identificador);
        return 1;
    }

    // Remoção dos elementos da lista
    for (int i = 0; i < pessoas_fora; i++) {
        scanf("%d", &identificador_2[i]);
        busca_e_remocao(&lista, identificador_2[i]);
    }

    // Imprimir a lista final
    imprimir_lista(&lista);

    free(identificador);
    free(identificador_2);

    printf("\n");
    return 0;
}
