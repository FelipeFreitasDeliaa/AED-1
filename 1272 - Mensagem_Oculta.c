/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>

void decifrar_palavra(char palavra[], int tamanho) {
    char decodificada[51];
    int j = 0;

    for (int i = 0; i < tamanho; i++) {
        if ((i == 0 || palavra[i - 1] == ' ') && palavra[i] != ' ') {
            decodificada[j] = palavra[i];
            j++;
        }
    }

    decodificada[j] = '\0';
    printf("%s\n", decodificada);
}

int main() {
    int teste;
    scanf("%d", &teste);
    getchar();

    char palavra[51];

    for (int i = 0; i < teste; i++){
        char palavra[51];
        int tamanho = 0;

        while (1){
            scanf ("%c", &palavra[tamanho]);
            if (palavra[tamanho] != '\n'){
                tamanho++;
            }
            else break;
        }
        palavra[tamanho] = '\0';

        decifrar_palavra(palavra, tamanho);
    }

    return 0;
}
