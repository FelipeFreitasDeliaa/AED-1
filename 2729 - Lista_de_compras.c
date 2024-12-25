/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char elemento[21];
    struct no* prox;
} NO;

NO* incluir_na_lista(NO* lista, char* item) {
    NO* novo_no = (NO*)malloc(sizeof(NO));
    strcpy(novo_no->elemento, item);
    novo_no->prox = NULL;

    NO* aux = lista;
    NO* anterior = NULL;
    while (aux != NULL) {
        if (strcmp(aux->elemento, item) == 0) { 
            free(novo_no);
            return lista;
        }
        if (strcmp(aux->elemento, item) > 0) break; 
        anterior = aux;
        aux = aux->prox;
    }

    if (anterior == NULL) { 
        novo_no->prox = lista;
        lista = novo_no;
    } else { 
        novo_no->prox = aux;
        anterior->prox = novo_no;
    }

    return lista;
}

void imprimir_lista(NO* lista) {
    NO* aux = lista;
    while (aux != NULL) {
        printf("%s", aux->elemento);
        if (aux->prox != NULL) printf(" ");
        aux = aux->prox;
    }
    printf("\n");
}

void liberar_lista(NO* lista) {
    NO* aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

int main() {
    int numero_de_listas;
    scanf("%d", &numero_de_listas);
    getchar();

    if (numero_de_listas < 1 || numero_de_listas > 100) {
        return 1;
    }

    for (int i = 0; i < numero_de_listas; i++) {
        NO* lista_de_compras = NULL;

        char linha[20001]; 
        fgets(linha, sizeof(linha), stdin);

        if (strlen(linha) > 0 && linha[strlen(linha) - 1] == '\n') {
            linha[strlen(linha) - 1] = '\0';
        }

        char* parcela = strtok(linha, " ");
        while (parcela != NULL) {
            lista_de_compras = incluir_na_lista(lista_de_compras, parcela);
            parcela = strtok(NULL, " ");
        }

        imprimir_lista(lista_de_compras);

        liberar_lista(lista_de_compras);
    }

    return 0;
}
