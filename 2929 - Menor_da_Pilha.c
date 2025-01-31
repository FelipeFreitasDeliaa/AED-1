/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int num;
    struct no* prox;
    struct no* anterior;
} NO;

NO* inserir_na_pilha(NO** topo, int valor) {
    NO* novo_no = (NO*)malloc(sizeof(NO));
    novo_no->num = valor;
    novo_no->prox = NULL;
    novo_no->anterior = *topo;
    if (*topo != NULL) {
        (*topo)->prox = novo_no;
    }
    *topo = novo_no;
    return *topo;
}

NO* retirar_da_pilha(NO** topo) {
    if (*topo == NULL) {
        printf("EMPTY\n");
        return NULL;
    }
    NO* aux = *topo;
    *topo = aux->anterior;
    if (*topo != NULL) {
        (*topo)->prox = NULL;
    }
    free(aux);
    return *topo;
}

void minimo(NO** topo) {
    NO* aux = *topo;
    if (aux == NULL) {
        printf("EMPTY\n");
    } else {
        int menor_numero = aux->num;
        while (aux != NULL) {
            if (aux->num < menor_numero) {
                menor_numero = aux->num;
            }
            aux = aux->anterior;
        }
        printf("%d\n", menor_numero);
    }
}

void liberar_pilha(NO** topo) {
    NO* aux = *topo;
    while (aux != NULL) {
        NO* temp = aux;
        aux = aux->anterior;
        free(temp);
    }
}

int main() {
    NO* topo = NULL;
    int N;
    char operacao[100];

    scanf("%d", &N);
    getchar(); 

    for (int i = 0; i < N; i++) {
        fgets(operacao, sizeof(operacao), stdin);
        char* parcela = strtok(operacao, " \n");

        if (strcmp(parcela, "POP") == 0) {
            topo = retirar_da_pilha(&topo);
        } else if (strcmp(parcela, "MIN") == 0) {
            minimo(&topo); 
        } else if (strcmp(parcela, "PUSH") == 0) { 
            parcela = strtok(NULL, " \n"); 
            if (parcela != NULL) {
                int numero = atoi(parcela);  
                topo = inserir_na_pilha(&topo, numero); 
            }
        }
    }

    liberar_pilha(&topo);
    return 0;
}
