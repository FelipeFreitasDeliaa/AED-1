/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <stdlib.h>

void calcular_diferenca(long long int soldados, long long int oponente) {
    long long int diferenca = llabs(soldados - oponente);
    printf("%lld\n", diferenca);
}

int main() {
    long long int soldados, oponente;

    while (scanf("%lld %lld", &soldados, &oponente) == 2) {
        calcular_diferenca(soldados, oponente);
    }

    return 0;
}
