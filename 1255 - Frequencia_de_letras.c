/*Felipe Freitas D' Elia
 RA: 176284*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void consultar_frequencia(char* texto, int* frequencia, int tamanho) {

    for (int i = 0; i < 26; i++) {
        frequencia[i] = 0;
    }

    for (int i = 0; i < tamanho; i++) {
        if (isalpha(texto[i])) { 
            char caractere = tolower(texto[i]);
            frequencia[caractere - 'a']++; 
        }
    }
}

int main() {
    int testes;
    scanf("%d", &testes);
    getchar(); 

    char linha[201]; 
    int frequencia[26];     
    char mais_frequentes[27]; 

    for (int i = 0; i < testes; i++) {
        fgets(linha, 201, stdin); 
        int tamanho = strlen(linha);

        if (linha[tamanho - 1] == '\n') {
            linha[tamanho - 1] = '\0';
            tamanho--;
        }

        consultar_frequencia(linha, frequencia, tamanho);

        int max_frequencia = 0;
        for (int j = 0; j < 26; j++) {
            if (frequencia[j] > max_frequencia) {
                max_frequencia = frequencia[j];
            }
        }

        int indice = 0;
        for (int j = 0; j < 26; j++) {
            if (frequencia[j] == max_frequencia) {
                mais_frequentes[indice++] = 'a' + j;
            }
        }
        mais_frequentes[indice] = '\0';

        printf("%s\n", mais_frequentes);
    }

    return 0;
}
