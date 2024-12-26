/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char elemento;
    struct no* prox;
} NO;

NO* empilhar(NO** topo, char item) {

    NO* novo_no = (NO*)malloc(sizeof(NO));

    novo_no->elemento = item;
    novo_no->prox = *topo;
    *topo = novo_no;

    return *topo;
}

NO* desempilhar(NO** topo) {

    if (*topo == NULL) return NULL; 

    NO* remover = *topo;

    *topo = (*topo)->prox;
    free(remover);

    return *topo;
}

int main() {
    char caso[1001];
    int qtd_casos;

    scanf("%d", &qtd_casos);
    getchar();

    for (int i = 0; i < qtd_casos; i++) {

        fgets(caso, 1001, stdin);

        int possivel_extrair = 0;
        NO* topo = NULL;

        for (int j = 0; caso[j] != '\0' && caso[j] != '\n'; j++) {

            if (caso[j] == '<') {
                topo = empilhar(&topo, caso[j]);

            } else if (caso[j] == '>') {
                if (topo == NULL) {
                    continue;
                } else {
                    topo = desempilhar(&topo);
                    possivel_extrair++;
                }
            }
        }

        while (topo != NULL) {
            topo = desempilhar(&topo);
        }

        printf("%d\n", possivel_extrair);
    }

    return 0;
}
