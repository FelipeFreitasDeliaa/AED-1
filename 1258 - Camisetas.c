/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[101];
    char cor[10];
    int tamanho;
    struct no* prox;
} NO;

int tamanho_para_numero(const char* tamanho) {
    if (strcmp(tamanho, "P") == 0) return 1;
    if (strcmp(tamanho, "M") == 0) return 2;
    if (strcmp(tamanho, "G") == 0) return 3;
    return 0;
}

const char* numero_para_tamanho(int tamanho) {
    switch (tamanho) {
        case 1: return "P";
        case 2: return "M";
        case 3: return "G";
    }
    return "";
}

void inserir_ordenado(NO** lista, char* nome, char* cor, int tamanho) {
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    strcpy(novo->cor, cor);
    novo->tamanho = tamanho;
    novo->prox = NULL;

    if (*lista == NULL || 
        strcmp(cor, (*lista)->cor) < 0 || 
        (strcmp(cor, (*lista)->cor) == 0 && tamanho < (*lista)->tamanho) || 
        (strcmp(cor, (*lista)->cor) == 0 && tamanho == (*lista)->tamanho && strcmp(nome, (*lista)->nome) < 0)) {
        novo->prox = *lista;
        *lista = novo;
        return;
    }

    NO* atual = *lista;
    while (atual->prox != NULL && 
          (strcmp(cor, atual->prox->cor) > 0 || 
          (strcmp(cor, atual->prox->cor) == 0 && tamanho > atual->prox->tamanho) || 
          (strcmp(cor, atual->prox->cor) == 0 && tamanho == atual->prox->tamanho && strcmp(nome, atual->prox->nome) > 0))) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

void imprimir(NO* lista) {
    NO* atual = lista;
    while (atual != NULL) {
        printf("%s %s %s\n", atual->cor, numero_para_tamanho(atual->tamanho), atual->nome);
        atual = atual->prox;
    }
}

void liberar_lista(NO** lista) {
    NO* atual = *lista;
    while (atual != NULL) {
        NO* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    *lista = NULL;
}

int main() {
    int N;
    int primeiro_caso = 1;

    while (1) {
        scanf("%d", &N);
        getchar(); 

        if (N == 0) break;

        NO* lista = NULL;

        for (int i = 0; i < N; i++) {
            char nome[101];
            char linha[21];
            char cor[10];
            char tamanho[3];
            int tamanho_num;

            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0'; 

            fgets(linha, sizeof(linha), stdin);
            linha[strcspn(linha, "\n")] = '\0'; 

            sscanf(linha, "%s %s", cor, tamanho);
            tamanho_num = tamanho_para_numero(tamanho);

            inserir_ordenado(&lista, nome, cor, tamanho_num);
        }

        if (!primeiro_caso) {
            printf("\n"); 
        }
        imprimir(lista);
        liberar_lista(&lista);

        primeiro_caso = 0;
    }

    return 0;
}
