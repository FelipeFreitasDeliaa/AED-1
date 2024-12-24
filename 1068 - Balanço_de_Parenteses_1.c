/*Felipe Freitas D' Elia
RA: 176284*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char caractere;
    struct no* prox;
} NO;

//empilhando as aberturas de parenteses
NO* empilhar(NO** pilha, char valor) { 
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->caractere = valor;
    novo->prox = *pilha;
    return novo;
}

//desempilhando o fechamento de parenteses
NO* desempilhar(NO** pilha) { 
    if (*pilha == NULL) return NULL;
    NO* remover = *pilha;
    *pilha = remover->prox;
    return remover;
}

//identificar se a expressão está correta
int identifica_expressao(char expressao[]) { 
    int i = 0;
    NO* pilha = NULL;

    while (expressao[i] != '\0') {
      
        if (expressao[i] == '(') {
            pilha = empilhar(&pilha, expressao[i]);
          
        } else if (expressao[i] == ')') {
            NO* remover = desempilhar(&pilha);
            if (remover == NULL) { //caso a pilha já estiver vazia
                return 0;
            }
            free(remover);
        }
        i++;
      
    }

    if (pilha == NULL) { 
        return 1;
    } else {
        while (pilha != NULL) {
            NO* remover = desempilhar(&pilha);
            free(remover);
        }
        return 0;
    }
}

int main() {
    char expressao[1001];
    int contador = 0; 
    const int limite = 10000; 

    while (fgets(expressao, sizeof(expressao), stdin)) {
        if (contador >= limite) {
            break;
        }
        
        //retira o caractere pulo de linha da expressão
        size_t len = strlen(expressao); 
        if (len > 0 && expressao[len - 1] == '\n') {
            expressao[len - 1] = '\0';
        }

        if (identifica_expressao(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }

        contador++; 
    }

    return 0;
}
