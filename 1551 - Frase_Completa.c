/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>

int verificar(char linha[], int tamanho) {
    int frequencia[26] = {0};
    int quantidade = 0;

    for (int i = 0; i < tamanho; i++) {
        if (linha[i] >= 'a' && linha[i] <= 'z') {
            if (frequencia[linha[i] - 'a'] == 0) {
                quantidade++;
                frequencia[linha[i] - 'a']++;
            }
        }
    }

    return quantidade;
}

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);
    getchar(); 

    for (int i = 0; i < casos_teste; i++) {
        char linha[1001];
        int tamanho = 0;
        char c;

        while ((c = getchar()) != '\n' && tamanho < 1000) {
            linha[tamanho++] = c;
        }
        linha[tamanho] = '\0'; 

        int quantidade = verificar(linha, tamanho);

        if (quantidade == 26) {
            printf("frase completa\n");
        } else if (quantidade >= 13) {
            printf("frase quase completa\n");
        } else {
            printf("frase mal elaborada\n");
        }
    }

    return 0;
}
