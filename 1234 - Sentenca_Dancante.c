/*Felipe Freitas D' Elia
 RA: 176284*/

#include <stdio.h>
#include <stdlib.h>

void modificar_string(char* palavra, int tamanho){
    char minusculas[26] = "abcdefghijklmnopqrstuvwxyz";
    char maiusculas[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int numero_de_maiusculas = 1;

    for (int i = 0; i < tamanho; i++){
        if (palavra[i] != ' '){
            int contador = 0;

            while ((minusculas[contador] != palavra[i]) && (maiusculas[contador] != palavra[i])) {
                contador++;
            }

            if (numero_de_maiusculas % 2 != 0){
                palavra[i] = maiusculas[contador];
            }
            else {
                palavra[i] = minusculas[contador];
            }
            numero_de_maiusculas++;
        }
    }
}

int main(){
    int tamanho;

    char* string = malloc(50 * sizeof(char));

    while(1){
        tamanho = 0;

        while (1) {
            char c;
            scanf("%c", &c);
            if (c == '\n') break;
            string[tamanho++] = c;
        }
        string[tamanho] = '\0';

        if (tamanho == 0){
            break;
        }
        else{
            modificar_string(string, tamanho);

            for (int i = 0; i < tamanho; i++) {
                printf("%c", string[i]);
            }
            printf("\n");
        }
    }

    free(string);
    return 0;
}
