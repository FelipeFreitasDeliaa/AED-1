/*Felipe Freitas D' Elia
            RA: 176284*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char amigo[100];
    struct no* prox;
} NO;

NO* inserir(NO* Lista, char amigo[]) {
    NO* novo_no = (NO*)malloc(sizeof(NO));
    strcpy(novo_no->amigo, amigo);
    novo_no->prox = NULL;

    if (Lista == NULL) {
        return novo_no;
    } else {
        NO* aux = Lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo_no;
        return Lista;
    }
}

NO* adicionar_no_meio(NO* Lista_antiga, char amigo_indicado[], NO* Lista_nova) {
    NO* aux = Lista_antiga;
    NO* aux_2 = Lista_nova;

    if (strcmp(aux->amigo, amigo_indicado) == 0) {
        while (aux_2->prox != NULL) {
            aux_2 = aux_2->prox;
        }
        aux_2->prox = Lista_antiga;
        return Lista_nova;
    } else {
        while (strcmp(aux->prox->amigo, amigo_indicado) != 0) {
            aux = aux->prox;
        }
        while (aux_2->prox != NULL) {
            aux_2 = aux_2->prox;
        }
        aux_2->prox = aux->prox;
        aux->prox = Lista_nova;
        return Lista_antiga;
    }
}

NO* adicionar_no_fim(NO* Lista_antiga, NO* Lista_nova) {
    NO* aux = Lista_antiga;

    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = Lista_nova;

    return Lista_antiga;
}

void imprimir_lista(NO* Lista) {
    NO* aux = Lista;
    while (aux != NULL) {
        printf("%s", aux->amigo); 
        if (aux->prox != NULL) {
            printf(" ");
        }
        aux = aux->prox;
    }
    printf("\n"); 
}

int main() {
    NO* Lista_antiga = NULL;
    NO* Lista_nova = NULL;

    char entrada[1000];
    char amigo[100];
    char amigo_indicado[100];

    fgets(entrada, sizeof(entrada), stdin);
    size_t len = strlen(entrada);
    if (len > 0 && entrada[len - 1] == '\n') {
        entrada[len - 1] = '\0';
    }
    char* parcela = strtok(entrada, " ");
    while (parcela != NULL) {
        strcpy(amigo, parcela);
        Lista_antiga = inserir(Lista_antiga, amigo);
        parcela = strtok(NULL, " ");
    }

    fgets(entrada, sizeof(entrada), stdin);
    len = strlen(entrada);
    if (len > 0 && entrada[len - 1] == '\n') {
        entrada[len - 1] = '\0';
    }
    parcela = strtok(entrada, " ");
    while (parcela != NULL) {
        strcpy(amigo, parcela);
        Lista_nova = inserir(Lista_nova, amigo);
        parcela = strtok(NULL, " ");
    }

    fgets(amigo_indicado, sizeof(amigo_indicado), stdin);
    len = strlen(amigo_indicado);
    if (len > 0 && amigo_indicado[len - 1] == '\n') {
        amigo_indicado[len - 1] = '\0';
    }

    if (strcmp(amigo_indicado, "nao") != 0) {
        Lista_antiga = adicionar_no_meio(Lista_antiga, amigo_indicado, Lista_nova);
    } else {
        Lista_antiga = adicionar_no_fim(Lista_antiga, Lista_nova);
    }

    imprimir_lista(Lista_antiga);

    return 0;
}
