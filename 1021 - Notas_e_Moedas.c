/*Felipe Freitas D' Elia
  RA: 176284*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    double valor;
    scanf("%lf", &valor);

    int total_centavos = (int)(valor * 100 + 0.5); 

    int notas[] = {10000, 5000, 2000, 1000, 500, 200}; 
    int moedas[] = {100, 50, 25, 10, 5, 1};

    printf("NOTAS:\n");
    for (int i = 0; i < 6; i++) {
        int quantidade = total_centavos / notas[i];
        total_centavos %= notas[i];
        printf("%d nota(s) de R$ %.2f\n", quantidade, notas[i] / 100.0);
    }

    printf("MOEDAS:\n");
    for (int i = 0; i < 6; i++) {
        int quantidade = total_centavos / moedas[i];
        total_centavos %= moedas[i];
        printf("%d moeda(s) de R$ %.2f\n", quantidade, moedas[i] / 100.0);
    }

    return 0;
}
