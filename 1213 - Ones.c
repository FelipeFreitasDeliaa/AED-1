/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numero;

    while (scanf("%d", &numero) == 1) {
        int resto = 0;
        int numero_de_digitos = 0;

        do {
            resto = (resto * 10 + 1) % numero;
            numero_de_digitos++;
        } while (resto != 0);

        printf("%d\n", numero_de_digitos);
    }

    return 0;
}
