/*Felipe Freitas D' Elia
  RA: 176284 */

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int num;
    struct no* prox;
} NO;

NO* incluir_na_lista(NO** Lista, int numero) {
    NO* novo_no = (NO*)malloc(sizeof(NO));
    novo_no->num = numero;
    novo_no->prox = NULL;

    if (*Lista == NULL || numero > (*Lista)->num) {
        novo_no->prox = *Lista;
        *Lista = novo_no;
    } else {
        NO* atual = *Lista;
        while (atual->prox != NULL && atual->prox->num >= numero) {
            atual = atual->prox;
        }
        novo_no->prox = atual->prox;
        atual->prox = novo_no;
    }

    return *Lista;
}

void liberar_lista(NO** Lista) {
    NO* atual = *Lista;
    while (atual != NULL) {
        NO* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    *Lista = NULL;
}

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);

    for (int i = 0; i < casos_teste; i++) {
        int numero_de_alunos;
        do {
            scanf("%d", &numero_de_alunos);
        } while (numero_de_alunos < 1 || numero_de_alunos > 1000);

        int* nota_do_aluno = malloc(numero_de_alunos * sizeof(int));
        NO* Lista = NULL;

        for (int j = 0; j < numero_de_alunos; j++) {
            do {
                scanf("%d", &nota_do_aluno[j]);
            } while (nota_do_aluno[j] < 1 || nota_do_aluno[j] > 1000);

            Lista = incluir_na_lista(&Lista, nota_do_aluno[j]);
        }

        NO* aux = Lista;
        int numero_que_nao_trocaram = 0;

        for (int k = 0; k < numero_de_alunos; k++) {
            if (nota_do_aluno[k] == aux->num) {
                numero_que_nao_trocaram++;
            }
            aux = aux->prox;
        }

        printf("%d\n", numero_que_nao_trocaram);

        liberar_lista(&Lista);
        free(nota_do_aluno);
    }

    return 0;
}
