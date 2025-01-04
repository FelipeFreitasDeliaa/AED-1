/*Felipe Freitas D' Elia
  RA: 176284
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALAVRAS 50
#define MAX_COMPRIMENTO 50
#define MAX_STRING 2550

typedef struct {
    char palavra[MAX_COMPRIMENTO + 1];
    int ordem_original;
    int tamanho; 
} Palavra;

int comparar_palavras(const void* a, const void* b) {
    Palavra* p1 = (Palavra*)a;
    Palavra* p2 = (Palavra*)b;

    if (p1->tamanho != p2->tamanho) {
        return p2->tamanho - p1->tamanho; 
    }
    return p1->ordem_original - p2->ordem_original;
}

int main() {
    int numero_de_casos;
    scanf("%d", &numero_de_casos);
    getchar(); 
    
    for (int i = 0; i < numero_de_casos; i++) {
        Palavra palavras[MAX_PALAVRAS];
        int contador = 0;

        char string[MAX_STRING];
        fgets(string, sizeof(string), stdin);

        int tamanho = strlen(string);
        if (tamanho > 0 && string[tamanho - 1] == '\n') {
            string[tamanho - 1] = '\0';
        }

        char* inicio = string;
        while (*inicio) {
            while (*inicio == ' ') inicio++; 
            if (!*inicio) break;

            char* fim = inicio;
            while (*fim && *fim != ' ') fim++; 

            int comprimento = fim - inicio;
            strncpy(palavras[contador].palavra, inicio, comprimento);
            palavras[contador].palavra[comprimento] = '\0';
            palavras[contador].ordem_original = contador;
            palavras[contador].tamanho = comprimento;
            contador++;

            inicio = fim;
        }

        qsort(palavras, contador, sizeof(Palavra), comparar_palavras);

        for (int j = 0; j < contador; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%s", palavras[j].palavra);
        }
        printf("\n");
    }

    return 0;
}
