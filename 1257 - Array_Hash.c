/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>

int posicao_do_elemento(int tamanho) {
    int total = 0;
    for (int i = 0; i < tamanho; i++) {
        total += i;
    }
    return total;
}

int posicao_no_alfabeto(char string[], int tamanho) {
    int total = 0;
    for (int i = 0; i < tamanho; i++) {
        total += (string[i] - 'A');
    }
    return total;
}

int main() {
    int testes;
    scanf("%d", &testes);
    getchar(); 

    for (int i = 0; i < testes; i++) {
        int qtd_linhas;
        scanf("%d", &qtd_linhas);
        getchar();

        int total = 0; 

        for (int contador = 0; contador < qtd_linhas; contador++) {
            char string[50];
            int tamanho = 0;
            char c;
            
            while (1) {
                c = getchar(); 
                if (c == '\n' || c == EOF) {
                    break;
                }
                string[tamanho] = c; 
                tamanho++; 
            }
            string[tamanho] = '\0';

            int alfabeto = posicao_no_alfabeto(string, tamanho);
            int posicao = posicao_do_elemento(tamanho); 
            int entrada = tamanho * contador;
            total += (alfabeto + posicao + entrada);
        }

        printf("%d\n", total);
    }

    return 0;
}
