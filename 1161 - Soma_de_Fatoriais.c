/*Felipe Freitas D' Elia 
  RA: 176284*/

#include <stdio.h>

unsigned long long int calcularFatorial(int n) {
    unsigned long long int fatorial = 1;
    for (int i = 1; i <= n; i++) {
        fatorial *= i;
    }
    return fatorial;
}

int main() {
    int numero_1, numero_2;

    while (1) {
    
        int resultadoLeitura = scanf("%d %d", &numero_1, &numero_2);

        if (resultadoLeitura != 2) {
            break; 
        }

        unsigned long long int fatorial_1 = calcularFatorial(numero_1);
        unsigned long long int fatorial_2 = calcularFatorial(numero_2);

        unsigned long long int total = fatorial_1 + fatorial_2;
        printf("%llu\n", total);
    }

    return 0;
}
