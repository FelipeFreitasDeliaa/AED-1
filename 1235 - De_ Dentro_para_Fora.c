/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>

void decifrar_linha(char *linha, int tamanho) {
    int metade = tamanho / 2;
  
    for (int i = 0, j = metade - 1; i < j; i++, j--) {
        char temp = linha[i];
        linha[i] = linha[j];
        linha[j] = temp;
    }

    for (int i = metade, j = tamanho - 1; i < j; i++, j--) {
        char temp = linha[i];
        linha[i] = linha[j];
        linha[j] = temp;
    }
}

int main() {
    int testes;
    scanf("%d", &testes);
    getchar();

    for (int t = 0; t < testes; t++) {
        char linha[101];
        int tamanho = 0;

        char c;
        while ((c = getchar()) != '\n' && c != EOF) {
            if (tamanho < 100) {
                linha[tamanho++] = c;
            }
        }
        linha[tamanho] = '\0';

        decifrar_linha(linha, tamanho);
        printf("%s\n", linha);
    }
  
    return 0;
}
