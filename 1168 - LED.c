/*Felipe Freitas D' Elia 
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>

int contador_de_leds(char numero_em_string[], int tamanho_da_string) {
    int leds_necessarios = 0;

    for (int i = 0; i < tamanho_da_string; i++) {
        switch (numero_em_string[i]) {
            case '0': leds_necessarios += 6; break;
            case '1': leds_necessarios += 2; break;
            case '2': leds_necessarios += 5; break;
            case '3': leds_necessarios += 5; break;
            case '4': leds_necessarios += 4; break;
            case '5': leds_necessarios += 5; break;
            case '6': leds_necessarios += 6; break;
            case '7': leds_necessarios += 3; break;
            case '8': leds_necessarios += 7; break;
            case '9': leds_necessarios += 6; break;
        }
    }

    return leds_necessarios;
}

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);
    getchar();

    char string_numero[101];

    for (int i = 0; i < casos_teste; i++) {
        int j = 0;

        // Leitura da string do número
        for (; j < 101; j++) {
            scanf("%c", &string_numero[j]);
            if (string_numero[j] == '\n') {
                string_numero[j] = '\0';
                break;
            }
        }

        int leds_necessarios = contador_de_leds(string_numero, j);
        printf("%d leds\n", leds_necessarios); 
    }

    return 0;
}
