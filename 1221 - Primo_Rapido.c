/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <math.h>

int eh_primo(unsigned long long int numero) {
    if (numero <= 1) return 0;
    if (numero == 2) return 1; 
    if (numero % 2 == 0) return 0;

    for (unsigned long long int i = 3; i <= sqrt(numero); i += 2) {
        if (numero % i == 0) {
            return 0; 
        }
    }

    return 1;
}

int main() {
    int testes;
    scanf("%d", &testes);

    for (int i = 0; i < testes; i++) {
        unsigned long long int numero;
        scanf("%llu", &numero);

        if (eh_primo(numero)) {
            printf("Prime\n");
        } else {
            printf("Not Prime\n");
        }
    }

    return 0;
}
