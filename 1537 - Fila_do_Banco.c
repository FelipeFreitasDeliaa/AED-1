/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>

#define MODULO 1000000009

unsigned long long fatorial_mod(int n) {
    unsigned long long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado = (resultado * i) % MODULO;
    }
    return resultado;
}

unsigned long long combinacao_mod(int n, int k) {
    unsigned long long resultado = 1;
    for (int i = 1; i <= k; i++) {
        resultado = (resultado * (n - k + i)) / i;
    }
    return resultado % MODULO;
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        
        unsigned long long combinacao = combinacao_mod(n, 3);
        unsigned long long fatorial_n_menos_3 = fatorial_mod(n - 3);
        unsigned long long resultado = (combinacao * fatorial_n_menos_3) % MODULO;

        printf("%llu\n", resultado);
    }

    return 0;
}
