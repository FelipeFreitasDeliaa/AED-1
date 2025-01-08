/*Felipe Freitas D' Elia
  RA: 176284 */

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int num;
    struct no* prox;
} NO;

NO* mover_para_base(NO** Topo) {
    if ((*Topo)->prox == NULL) return *Topo;

    NO* mover = *Topo;
    *Topo = mover->prox;

    NO* aux = *Topo;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = mover;
    mover->prox = NULL;

    return *Topo;
}

NO* remover_do_topo(NO** Topo, int* valor_removido) {

    NO* remover = *Topo;
    *valor_removido = remover->num;

    *Topo = remover->prox;
    free(remover);

    return *Topo;
}

NO* inserir_na_lista(NO** Topo, int num) {
    NO* novo_no = (NO*)malloc(sizeof(NO));
    novo_no->num = num;
    novo_no->prox = NULL;

    if (*Topo == NULL) {
        *Topo = novo_no;
    } else {
        NO* aux = *Topo;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo_no;
    }

    return *Topo;
}

int main() {
    int n_cartas;

    while (1) {
        scanf("%d", &n_cartas);

        if (n_cartas == 0) {
            break;
        }

        NO* Topo = NULL;

        for (int i = 1; i <= n_cartas; i++) {
            inserir_na_lista(&Topo, i);
        }

        int* cartas_removidas = malloc((n_cartas - 1) * sizeof(int));
        int indice = 0;
        int carta_remanescente;

        while (Topo->prox != NULL) {
            int removida;
            Topo = remover_do_topo(&Topo, &removida);
            cartas_removidas[indice++] = removida;

            Topo = mover_para_base(&Topo);
        }

        carta_remanescente = Topo->num;

        printf("Discarded cards: ");
        for (int i = 0; i < indice; i++) {
            if (i > 0) printf(", ");
            printf("%d", cartas_removidas[i]);
        }
        printf("\nRemaining card: %d\n", carta_remanescente);

        free(cartas_removidas);
        free(Topo);
    }

    return 0;
}
